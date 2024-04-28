#include "call_data.hpp"

namespace deulee {

CallData::CallData(matching::MatchingService::AsyncService* service, grpc::ServerCompletionQueue* cq)
		: service_(service), cq_(cq)
{
}

CallData::~CallData() {}

} // namespace deulee
