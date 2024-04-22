#include "movement_prototype.hpp"

namespace deulee {

MovementPrototype::MovementPrototype() {
}

MovementPrototype::~MovementPrototype() {
}

Prototype* MovementPrototype::Clone() const {
	return new MovementPrototype(*this);
}

Message MovementPrototype::MessageHandler(const Message& message) {
	std::cout << "MovementPrototype::MessageHandler" << std::endl;
	std::cout << "message debug_string: " << message.DebugString() << std::endl;
	return message;
};

} // namespace deulee
