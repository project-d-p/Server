#include <memory>
#include "server.hpp"
#include "session.hpp"

namespace deulee {

Server::Server(boost::asio::io_context& io_context, unsigned short port)
	: acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
	Accept();
}

void Server::Accept() {
	acceptor_.async_accept([this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket) {
		if (!ec) {
			std::make_shared<Session>(std::move(socket))->start();
		}
		Accept();
	});
}

} // namespace deulee
