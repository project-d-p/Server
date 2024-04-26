#include "call_data_attach_player.hpp"
#include <vector>
#include "server.hpp"
#include "channel.hpp"

namespace deulee {

CallDataAttachPlayer::CallDataAttachPlayer(matching::MatchingService::AsyncService* service, grpc::ServerCompletionQueue* cq)
		: CallData(service, cq), at_responder_(&ctx_), status_(CREATE)
{
	Proceed();
}

CallDataAttachPlayer::~CallDataAttachPlayer() {}

void CallDataAttachPlayer::Proceed() {
	if (status_ == CREATE) {
		status_ = PROCESS;
		service_->RequestAttachPlayer(&ctx_, &attach_request_, &at_responder_, cq_, cq_, this);
	} else if (status_ == PROCESS) {
		new CallDataAttachPlayer(service_, cq_);

		// Do Some Work : Maybe Call Some Function
		std::string channel_id = attach_request_.channel_id();
		std::shared_ptr<Channel> channel = Server::GetChannel(std::stoi(channel_id));
		for (auto& player : attach_request_.player_token()) {
			channel->AttachPlayer(player);
		}
		
		attach_response_.set_status(1);

		status_ = FINISH;
		at_responder_.Finish(attach_response_, grpc::Status::OK, this);
	} else {
		GPR_ASSERT(status_ == FINISH);
		delete this;
	}
}

} // namespace deulee
