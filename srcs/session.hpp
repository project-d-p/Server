#pragma once

#include <boost/asio.hpp>

namespace deulee {

class Session : public std::enable_shared_from_this<Session> {
private:
	boost::asio::ip::tcp::socket socket_;
	enum { max_length = 1024 };
	char data_[max_length];
	
	void read();
	void write(std::size_t length);

public:
	Session() = delete;
	Session(const Session&) = delete;
	Session& operator=(const Session&) = delete;
	Session(boost::asio::ip::tcp::socket socket);
	~Session();

	void start();
};

} // namspace deulee
