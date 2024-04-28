#pragma once

#include <boost/asio.hpp>
#include <grpcpp/grpcpp.h>

#include "grpc_match.grpc.pb.h"
#include "call_data.hpp"

namespace deulee {

class CallDataAttachPlayer : public CallData {
private:
	matching::RequestLaunch attach_request_;
	matching::ResponseLaunch attach_response_;

	grpc::ServerAsyncResponseWriter<matching::ResponseLaunch> at_responder_;

	enum CallStatus { CREATE, PROCESS, FINISH };
	CallStatus status_;

public:
	CallDataAttachPlayer(matching::MatchingService::AsyncService* service, grpc::ServerCompletionQueue* cq);
	virtual ~CallDataAttachPlayer();
	virtual void Proceed();
};

} // namespace deulee
