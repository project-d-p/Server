#pragma once

#include "message.pb.h"
#include <queue>
#include <mutex>

namespace deulee {

class DoubleBuffer {
private:
	enum {READ = 0, WRITE = 1};
	std::mutex mutex_;
	std::queue<Message>* ptr_[2];
	alignas(64) std::queue<Message> rw_queue_first_;
	alignas(64) std::queue<Message> rw_queue_second_;
public:
	DoubleBuffer();
	void FillBuffer(Message& message);
	void SwapBuffer();
	Message ReadBuffer();
	int GetSize();
};

} // namespace deulee
