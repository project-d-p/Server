#pragma once

#include <boost/asio.hpp>
#include <memory>
#include <vector>
#include "channel.hpp"

namespace deulee {

class Server {
private:
	boost::asio::ip::tcp::acceptor acceptor_;
	std::vector<std::shared_ptr<Channel>> channels_;

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
