#include "channel.hpp"

namespace deulee {

Channel::Channel(unsigned int channel_id, boost::asio::io_context& io_context, const unsigned int port, int timerfd)
	: channel_id_(channel_id),
	  instance_socket_(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)),
	  timer_fd_(io_context, timerfd)
{
	this->ChannelRead();
	this->ProcessMessage();
}

void Channel::AttachSession(std::shared_ptr<Session> session, std::string player_id)
{
	// udp_sessions_[player_id] = session->GetUdpEndPoint();
	// std::cout << "Udp endpoint attached" << std::endl;
	// std::cout << udp_sessions_[player_id].address().to_string() << std::endl;
	// std::cout << udp_sessions_[player_id].port() << std::endl;
	tcp_sessions_[player_id] = session;
	SessionRead(player_id);
	std::cout << "Session attached" << std::endl;
}

void Channel::SessionRead(std::string player_id)
{
	tcp_sessions_[player_id]->read(tcp_message_queue_);
}

void Channel::SessionWrite(const Message& message)
{
	for (auto& session : tcp_sessions_) {
		session.second->write(message);
	}
}

void Channel::ProcessMessage()
{
	timer_fd_.async_read_some(boost::asio::null_buffers(), [this](boost::system::error_code ec, std::size_t /*length*/) {
		if (ec) {
			return ;
		}
		while (!tcp_message_queue_.empty() || !udp_message_queue_.empty()) {
			if (!tcp_message_queue_.empty()) {
				Message message = tcp_message_queue_.front();
				tcp_message_queue_.pop();
				Prototype* prototype = PrototypeFactory::GetPrototype(message);
				Message return_message = prototype->MessageHandler(message);
				this->SessionWrite(return_message);
				delete prototype;
			}
			if (!udp_message_queue_.empty()) {
				Message message = udp_message_queue_.front();
				udp_message_queue_.pop();
				Prototype* prototype = PrototypeFactory::GetPrototype(message);
				prototype->MessageHandler(message);
				this->ChannelWrite(message);
				delete prototype;
			}
		}
		this->ProcessMessage();
	});
}

void Channel::ChannelRead()
{
	instance_socket_.async_receive_from(boost::asio::buffer(read_data_, MAX_LENGTH),
		instance_endpoint_, 
		[this](boost::system::error_code ec, std::size_t length) {
			if (!ec) {
				this->udp_sessions_[instance_endpoint_.address().to_string()] = instance_endpoint_;
				Message message(ProtobufMannager::Deserialize(read_data_));
				memset(read_data_, 0, MAX_LENGTH);
				this->udp_message_queue_.push(message);
				this->ChannelRead();
			}
	});
}

void Channel::ChannelWrite(const Message& message)
{
	ProtobufMannager::Serialize(write_data_, message);
	size_t length = message.ByteSizeLong() + sizeof(uint32_t);
	for (auto& udp_session : udp_sessions_) {
		instance_socket_.async_send_to(boost::asio::buffer(write_data_, length),
			udp_session.second, [this](boost::system::error_code ec, std::size_t /*length*/) {
				if (ec) {
					return ;
				}
			});
	}
}

std::string Channel::GetChannelId() const
{
	return std::to_string(channel_id_);
}

std::string Channel::GetUdpPort() const
{
	return std::to_string(instance_socket_.local_endpoint().port());
}

std::string Channel::GetUdpIp() const
{
	return instance_socket_.local_endpoint().address().to_string();
}

void Channel::AttachPlayer(std::string player_id) {
	players_.push_back(player_id);
}

Channel::~Channel()
{
	instance_socket_.close();
	timer_fd_.close();
}

} // namespace deulee
