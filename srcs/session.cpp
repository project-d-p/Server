#include <iostream>
#include "session.hpp"
#include "protobuf_mannager.hpp"

namespace deulee {

Session::Session(boost::asio::ip::tcp::socket socket)
	: socket_(std::move(socket))
{
}

void Session::start() 
{
	read();
}

void Session::read()
{
	auto self(shared_from_this());
	socket_.async_read_some(boost::asio::buffer(data_, max_length),
		[this, self](boost::system::error_code ec, std::size_t length) {
			if (!ec) {
				Message message(ProtobufMannager::Deserialize(data_));
				ProtobufMannager::Serialize(data_, message);
				write(length);
				memset(data_, 0, max_length);
			}
	});
}

void Session::write(std::size_t length)
{
	auto self(shared_from_this());
	boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
		[this, self](boost::system::error_code ec, std::size_t length) {
			if (!ec) {
				read();
			}
	});
}

Session::~Session()
{
	socket_.close();
}

} // namespace deulee
