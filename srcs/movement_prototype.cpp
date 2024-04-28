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

	// Vec3 orientation;
	// orientation.set_x(1.0f);
	// orientation.set_y(2.0f);
	// orientation.set_z(3.0f);

	// Vec3 progress_vector;
	// progress_vector.set_x(0.5f);
	// progress_vector.set_y(0.5f);
	// progress_vector.set_z(2.0f);

	// Movement move;
	// move.set_player_id("player1");
	// *move.mutable_orientation() = orientation;
	// *move.mutable_progess_vector() = progress_vector;
	// move.set_state(State::STATE_RUN);
	// move.set_timestamp("2021-01-01T12:00:00Z");

	// Message return_msg;
	// *return_msg.mutable_movement() = move;

	std::cout << "message debug_string: " << message.DebugString() << std::endl;
	return message;
};

} // namespace deulee
