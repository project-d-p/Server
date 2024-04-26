#include <iostream>
#include "session.hpp"
#include "protobuf_mannager.hpp"
#include "server.hpp"

namespace deulee {

Session::Session(boost::asio::ip::tcp::socket socket)
	: socket_(std::move(socket)), player_id_("")
{
}

void Session::Start()
{
	auto self(shared_from_this());
	socket_.async_read_some(boost::asio::buffer(data_, max_length),
		[this, self](boost::system::error_code ec, std::size_t length) {
			if (!ec) {
				Message message(ProtobufMannager::Deserialize(data_));
				Attachment attachment = message.attach();
				std::string channel_id = attachment.channel_id();
				this->player_id_ = attachment.player_id();
				Server::GetChannel(std::stoi(channel_id))->AttachSession(self, this->player_id_);
				memset(data_, 0, max_length);
			}
	});
}

void Session::read(std::queue<Message>& tcp_message_queue)
{
	socket_.async_read_some(boost::asio::buffer(data_, max_length),
		[this, &tcp_message_queue](boost::system::error_code ec, std::size_t length) {
			if (!ec) {
				Message message(ProtobufMannager::Deserialize(data_));
				tcp_message_queue.push(message);
				memset(data_, 0, max_length);
				this->read(tcp_message_queue);
			}
	});
}

void Session::write(const Message& message)
{
	ProtobufMannager::Serialize(data_, message);
	size_t length = message.ByteSizeLong() + sizeof(uint32_t);
	std::cout << "message_length_to_send: " << length << std::endl;
	boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
		[this](boost::system::error_code ec, std::size_t length) {
			if (!ec) {
			}
	});
}

boost::asio::ip::udp::endpoint Session::GetUdpEndPoint()
{
	boost::asio::ip::tcp::endpoint tcp_endpoint = socket_.remote_endpoint();
	std::string ip = tcp_endpoint.address().to_string();
	std::string port = std::to_string(tcp_endpoint.port());
	return boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(ip), std::stoi(port));
}

Session::~Session()
{
	socket_.close();
}

} // namespace deulee
