#include "channel.hpp"

namespace deulee {

Channel::Channel(boost::asio::io_context& io_context, const unsigned int port, int timerfd)
	: instance_socket_(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)),
	  timerfd_(timerfd),
	  timer_fd_(io_context, timerfd)
{
	this->ChannelRead();
	this->ProcessMessage();
}

void Channel::AttachSession(std::shared_ptr<Session> session)
{
	tcp_sessions_.push_back(session);
	SessionRead();
	std::cout << "Session attached" << std::endl;
}

void Channel::SessionRead()
{
	tcp_sessions_.back()->read(tcp_message_queue_);
}

void Channel::SessionWrite(const Message& message)
{
	for (auto& session : tcp_sessions_) {
		session->write(message);
	}
}

void Channel::ProcessMessage()
{
	timer_fd_.async_read_some(boost::asio::null_buffers(), [this](boost::system::error_code ec, std::size_t /*length*/) {
		if (ec) {
			return ;
		}
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
		this->ProcessMessage();
	});
}

void Channel::ChannelRead()
{
	instance_socket_.async_receive_from(boost::asio::buffer(read_data_, MAX_LENGTH),
		instance_endpoint_, 
		[this](boost::system::error_code ec, std::size_t length) {
			if (!ec) {
				if (udp_sessions_.size() <= 3 && std::find(udp_sessions_.begin(), udp_sessions_.end(), instance_endpoint_) == udp_sessions_.end()){
					udp_sessions_.push_back(instance_endpoint_);
				}
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
			udp_session, [this](boost::system::error_code ec, std::size_t /*length*/) {
				if (ec) {
					return ;
				}
			});
	}
}

Channel::~Channel()
{
	instance_socket_.close();
	close(timerfd_);
	timer_fd_.close();
}

} // namespace deulee
