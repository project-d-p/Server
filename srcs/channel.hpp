#pragma once

#include "double_buffer.hpp"
#include "session.hpp"
#include "protobuf_mannager.hpp"
#include "prototype_factory.hpp"
#include "prototype.hpp"
#include "message.pb.h"
#include "boost/asio.hpp"
#include <vector>
#include <queue>
#include <utility>
#include <memory>
#include <iostream>
#include <sys/timerfd.h>
#include <unistd.h>
#include <cstring>
#include <map>

namespace deulee {

class Channel : public std::enable_shared_from_this<Channel> {
private:
	unsigned int channel_id_;
	boost::asio::ip::udp::socket instance_socket_;
	boost::asio::posix::stream_descriptor timer_fd_;
	boost::asio::ip::udp::endpoint instance_endpoint_;
	std::vector<std::string> players_;
	std::map<std::string, std::shared_ptr<Session>> tcp_sessions_;
	std::map<std::string, boost::asio::ip::udp::endpoint> udp_sessions_;
	std::map<std::string, DoubleBuffer> tcp_message_queue_;
	DoubleBuffer udp_message_queue_;
	// 여기서 아마 queue에서 data race가 발생할 것.
	// 각각의 스레드가 독립적인 메모리에 접근하게 하고 싶음.
	
	enum { MAX_LENGTH = 1024 };
	char read_data_[MAX_LENGTH];
	char write_data_[MAX_LENGTH];

private:
	void SessionRead(std::string player_id);
	void SessionWrite(const Message& message);
	void ProcessMessage();
	void ChannelRead();
	void ChannelWrite(const Message& message);

public:
	Channel(unsigned int channel_id, boost::asio::io_context& network_context,
			boost::asio::io_context& logic_context, const unsigned int port, int timerfd);

	void AttachSession(std::shared_ptr<Session> session, std::string player_id);
	void AttachPlayer(std::string player_id);
	std::string GetChannelId() const;
	std::string GetUdpPort() const;
	std::string GetUdpIp() const;
	~Channel();
};

} // namespace deulee
