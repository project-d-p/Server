#pragma once

#include <boost/asio.hpp>
#include <memory>
#include <queue>
#include "message.pb.h"
#include "protobuf_mannager.hpp"

namespace deulee {

class Session : public std::enable_shared_from_this<Session> {
private:
	boost::asio::ip::tcp::socket socket_;
	std::string player_id_;
	enum { max_length = 1024 };
	char data_[max_length];
	
public:
	Session() = delete;
	Session(const Session&) = delete;
	Session& operator=(const Session&) = delete;
	Session(boost::asio::ip::tcp::socket socket);
	void Start();
	void read(std::queue<Message>& tcp_message_queue);
	void write(const Message& message);
	boost::asio::ip::udp::endpoint GetUdpEndPoint();
	~Session();

	// void start();
};

} // namspace deulee
