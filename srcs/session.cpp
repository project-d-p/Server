#include <iostream>
#include "session.hpp"
#include "protobuf_mannager.hpp"

namespace deulee {

Session::Session(boost::asio::ip::tcp::socket socket)
	: socket_(std::move(socket))
{
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
	boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
		[this](boost::system::error_code ec, std::size_t length) {
			if (!ec) {
			}
	});
}

Session::~Session()
{
	socket_.close();
}

} // namespace deulee
