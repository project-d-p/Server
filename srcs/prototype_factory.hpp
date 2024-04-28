#pragma once

#include <unordered_map>
#include <string>
#include "prototype.hpp"
#include "message.pb.h"

namespace deulee {

class PrototypeFactory {
private:
	static std::unordered_map<int, Prototype*> prototypes_;
public:
	PrototypeFactory();
	~PrototypeFactory();
	static Prototype* GetPrototype(const Message& key);
	// static void AddPrototype(const Message& key, Prototype* prototype);
};

} // namespace deulee
