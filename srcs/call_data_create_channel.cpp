#include "call_data_create_channel.hpp"
#include "server.hpp"
#include "channel.hpp"

namespace deulee {

CallDataCreateChannel::CallDataCreateChannel(matching::MatchingService::AsyncService* service, grpc::ServerCompletionQueue* cq)
		: CallData(service, cq), ch_responder_(&ctx_), status_(CREATE)
{
	Proceed();
}

CallDataCreateChannel::~CallDataCreateChannel() {}

void CallDataCreateChannel::Proceed() {
	if (status_ == CREATE) {
		status_ = PROCESS;
		service_->RequestCreateChannel(&ctx_, &create_request_, &ch_responder_, cq_, cq_, this);
	} else if (status_ == PROCESS) {
		new CallDataCreateChannel(service_, cq_);

		std::shared_ptr<Channel> channel = Server::CreateChannel();
		
		create_response_.set_channel_id(channel->GetChannelId());
		create_response_.set_udp_ip(channel->GetUdpIp());
		create_response_.set_udp_port(channel->GetUdpPort());
		create_response_.set_tcp_ip(Server::GetTcpIp());
		create_response_.set_tcp_port(Server::GetTcpPort());

		status_ = FINISH;
		ch_responder_.Finish(create_response_, grpc::Status::OK, this);
	} else {
		GPR_ASSERT(status_ == FINISH);
		delete this;
	}
}

} // namespace deulee
