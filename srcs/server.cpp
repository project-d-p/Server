#include <memory>
#include "server.hpp"
#include "session.hpp"

namespace deulee {

Server::Server(boost::asio::io_context& io_context, unsigned short port)
	: acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
	Accept();
	int timerfd = timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK);
	if (timerfd == -1) {
		std::cerr << "timerfd_create error" << std::endl;
		exit(1);
	}

	itimerspec new_value;
	new_value.it_value.tv_sec = 0;
	new_value.it_value.tv_nsec = 30 * 1000000;
	new_value.it_interval.tv_sec = 0;
	new_value.it_interval.tv_nsec = 30 * 1000000;

	if (timerfd_settime(timerfd, 0, &new_value, NULL) == -1) {
		std::cerr << "timerfd_settime error" << std::endl;
		close(timerfd);
		exit(1);
	}

	channels_.push_back(std::make_shared<Channel>(io_context, 5000, timerfd));
}

void Server::Accept() {
	acceptor_.async_accept([this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket) {
		if (!ec) {
			channels_.back()->AttachSession(std::make_shared<Session>(std::move(socket)));
		}
		Accept();
	});
}

Server::~Server() {
	acceptor_.close();
}

} // namespace deulee
