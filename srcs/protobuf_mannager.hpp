#pragma once

#include "../proto_build/message.pb.h"

namespace deulee {

class ProtobufMannager {
private:
	static std::string CreatePacket(const std::string& serialized_message);
public:
	ProtobufMannager();
	~ProtobufMannager();
	ProtobufMannager(const ProtobufMannager&) = delete;
	ProtobufMannager& operator=(const ProtobufMannager&) = delete;

	static void Serialize(char* buf, const Message& message);
	static Message Deserialize(const char* buf);
};

} // namespace deulee
