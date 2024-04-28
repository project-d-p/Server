#pragma once

#include <boost/asio.hpp>
#include <grpcpp/grpcpp.h>

#include "grpc_match.grpc.pb.h"
#include "call_data.hpp"

namespace deulee {

class CallDataCreateChannel : public CallData {
private:
	matching::Empty create_request_;
	matching::ChannelResponse create_response_;

	grpc::ServerAsyncResponseWriter<matching::ChannelResponse> ch_responder_;

	enum CallStatus { CREATE, PROCESS, FINISH };
	CallStatus status_;

public:
	CallDataCreateChannel(matching::MatchingService::AsyncService* service, grpc::ServerCompletionQueue* cq);
	virtual void Proceed();
	virtual ~CallDataCreateChannel();
};

} // namespace deulee
