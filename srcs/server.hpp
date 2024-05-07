#pragma once

#include <boost/asio.hpp>
#include <memory>
#include <vector>
#include <grpcpp/grpcpp.h>
#include <vector>
#include <thread>

#include "call_data_create_channel.hpp"
#include "call_data_attach_player.hpp"
#include "channel.hpp"

// #include "absl/flags/flag.h"
// #include "absl/flags/parse.h"
// #include "absl/strings/str_format.h"

#include "grpc_match.grpc.pb.h"
// #include <grpcpp/support/log.h>

namespace deulee {

class Server {
private:
	static std::map<unsigned int, std::shared_ptr<Channel>> channel_;
	static boost::asio::io_context logic_context_;
	static boost::asio::io_context network_context_;
	static boost::asio::ip::tcp::acceptor acceptor_;
	boost::asio::io_context::work logic_work_;
	boost::asio::io_context::work network_work_;
	
private:
	std::thread grpc_thread_;
	std::unique_ptr<grpc::Server> grpc_server_;
	std::unique_ptr<grpc::ServerCompletionQueue> grpc_cq_;
	matching::MatchingService::AsyncService grpc_service_;
	enum {GAME_THREADS = 4, NETWORK_THREADS = 4};
	std::vector<std::thread> game_threads_;
	std::vector<std::thread> network_threads_;

private:
	void Accept();
	void GrpcRun(unsigned short port);
	void GameRun();
	void NetworkRun();
	void HandleGrpcRequest();

public:
	Server(const Server&) = delete;
	Server& operator=(const Server&) = delete;
	Server();
	~Server();
	static std::shared_ptr<Channel> CreateChannel();
	static std::shared_ptr<Channel> GetChannel(unsigned int channel_id);
	static std::string GetTcpIp();
	static std::string GetTcpPort();
};

} // namespace deulee
