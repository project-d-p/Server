#include "session.hpp"

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
				write();
			}
	});
}

void Session::write()
{
	auto self(shared_from_this());
	boost::asio::async_write(socket_, boost::asio::buffer(data_, max_length),
		[this, self](boost::system::error_code ec, std::size_t length) {
			if (!ec) {
				read();
			}
	});
}

} // namespace deulee
