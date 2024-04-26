#include <memory>
#include "server.hpp"
#include "session.hpp"

#include <absl/strings/str_format.h>

namespace deulee {

std::map<unsigned int, std::shared_ptr<Channel>> Server::channel_;
boost::asio::ip::tcp::acceptor Server::acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 4242));

void Server::GrpcRun(unsigned short port) {
	std::string server_address = absl::StrFormat("0.0.0.0:%d", port);

	grpc::ServerBuilder builder;
	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	builder.RegisterService(&grpc_service_);
	grpc_cq_ = builder.AddCompletionQueue();
	grpc_server_ = builder.BuildAndStart();
	std::cout << "gRPC server listening on " << server_address << std::endl;

	grpc_thread_ = std::thread(&Server::HandleGrpcRequest, this);
	grpc_thread_.detach();
}

void Server::HandleGrpcRequest() {
	new CallDataCreateChannel(&grpc_service_, grpc_cq_.get());
	new CallDataAttachPlayer(&grpc_service_, grpc_cq_.get());
	void* tag;
	bool ok;
	while (true) {
		GPR_ASSERT(grpc_cq_->Next(&tag, &ok));
		GPR_ASSERT(ok);
		static_cast<CallData*>(tag)->Proceed();
	}
}

Server::Server(boost::asio::io_context& io_context, unsigned short port)
{
	this->GrpcRun(50051);
	Accept();

}

void Server::Accept() {
	acceptor_.async_accept([this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket) {
		if (!ec) {
			// Below is for Real
			// std::make_shared<Session>(std::move(socket))->Start();

			// Below /is for Testings
			channel_[1]->AttachSession(std::make_shared<Session>(std::move(socket)), "1");
		}
		Accept();
	});
}

std::shared_ptr<Channel> Server::CreateChannel() {
	static unsigned int port = 5000;
	static int channel_id = 0;
	channel_id++;
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

	std::shared_ptr<Channel> channel = std::make_shared<Channel>(channel_id, io_context, port++, timerfd);
	channel_[channel_id] = channel;
	return channel;
}

Server::~Server() {
	acceptor_.close();
	grpc_server_->Shutdown();
	grpc_cq_->Shutdown();
}

std::string Server::GetTcpIp() {
	return acceptor_.local_endpoint().address().to_string();
}

std::string Server::GetTcpPort() {
	return std::to_string(acceptor_.local_endpoint().port());
}

std::shared_ptr<Channel> Server::GetChannel(unsigned int channel_id) {
	return channel_[channel_id];
}

} // namespace deulee
