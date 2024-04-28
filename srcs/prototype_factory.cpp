#include "prototype_factory.hpp"
#include "movement_prototype.hpp"

namespace deulee {

std::unordered_map<int, Prototype*> PrototypeFactory::prototypes_;

PrototypeFactory::PrototypeFactory() {
	prototypes_[Message::kMovement] = new MovementPrototype();
}

Prototype* PrototypeFactory::GetPrototype(const Message& key) {
	return prototypes_[static_cast<int>(key.message_type_case())]->Clone();
}

// void PrototypeFactory::AddPrototype(const Message& key, Prototype* prototype) {
// 	prototypes_[static_cast<int>(key.message_type_case())] = prototype;
// }

PrototypeFactory::~PrototypeFactory() {
	for (auto& prototype : prototypes_) {
		delete prototype.second;
	}
}

} // namespace deulee
