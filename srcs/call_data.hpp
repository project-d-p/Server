#pragma once

#include "grpc_match.grpc.pb.h"

namespace deulee {

class CallData {
protected:
	matching::MatchingService::AsyncService* service_;
	grpc::ServerCompletionQueue* cq_;
	grpc::ServerContext ctx_;
public:
	CallData(matching::MatchingService::AsyncService* service, grpc::ServerCompletionQueue* cq);
	virtual void Proceed() = 0;
	virtual ~CallData();
};

} // namespace deulee
