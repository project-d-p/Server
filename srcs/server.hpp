#pragma once

#include <boost/asio.hpp>

namespace deulee {

class Server {
private:
	boost::asio::ip::tcp::acceptor acceptor_;

private:
	void Accept();

public:
	Server() = delete;
	Server(const Server&) = delete;
	Server& operator=(const Server&) = delete;
	Server(boost::asio::io_context& io_context, unsigned short port);
	~Server();
};

} // namespace deulee
