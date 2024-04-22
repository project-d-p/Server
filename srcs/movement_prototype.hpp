#pragma once

#include "message.pb.h"
#include "prototype.hpp"

namespace deulee {

class MovementPrototype : public Prototype {
public:
	MovementPrototype();
	virtual ~MovementPrototype();
	virtual Prototype* Clone() const override;
	virtual Message MessageHandler(const Message& message) override;
};

} // namespace deulee
