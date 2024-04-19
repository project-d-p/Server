#include "protobuf_mannager.hpp"

namespace deulee {
	ProtobufMannager::ProtobufMannager() {}
	ProtobufMannager::~ProtobufMannager() {}

	std::string ProtobufMannager::CreatePacket(const std::string& serialized_message) {
		uint32_t message_size = static_cast<int>(serialized_message.size());
		
		std::vector<uint8_t> buffer;
		buffer.resize(sizeof(message_size) + message_size);
		memcpy(buffer.data(), &message_size, sizeof(message_size));
		memcpy(buffer.data() + sizeof(message_size), serialized_message.data(), message_size);
		std::string ret_message(buffer.data(), buffer.data() + buffer.size());
		return ret_message;
	}

	void ProtobufMannager::Serialize(char* buf, const Message& message) {
		memset(buf, 0, sizeof(buf));

		std::string serialized_message;
		message.SerializeToString(&serialized_message);
		std::string packet = CreatePacket(serialized_message);
		memcpy(buf, packet.c_str(), packet.size());
	}

	Message ProtobufMannager::Deserialize(const char* buf) {
		std::vector<uint8_t> buffer(buf, buf + sizeof(uint32_t));
		uint32_t packet_size;
		memcpy(&packet_size, buffer.data(), sizeof(packet_size));
		std::string serialized_message(buf + sizeof(packet_size), packet_size);
		Message deserialized_message;
		deserialized_message.ParseFromString(serialized_message);
		return deserialized_message;
	}
}
