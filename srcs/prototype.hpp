#pragma once

#include "message.pb.h"

namespace deulee {

class Prototype {
public:
	virtual ~Prototype() = default;
	virtual Prototype* Clone() const = 0;
	virtual Message MessageHandler(const Message&) = 0;
};

} // namespace deulee
