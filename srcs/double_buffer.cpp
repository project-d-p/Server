#include "double_buffer.hpp"

namespace deulee {

DoubleBuffer::DoubleBuffer()
{
	ptr_[0] = &rw_queue_first_;
	ptr_[1] = &rw_queue_second_;
}

void DoubleBuffer::FillBuffer(Message& message) {
	std::lock_guard<std::mutex> lock(mutex_);
	ptr_[WRITE]->push(message);
}

void DoubleBuffer::SwapBuffer() {
	std::lock_guard<std::mutex> lock(mutex_);
	std::swap(this->ptr_[0], this->ptr_[1]);
}

Message DoubleBuffer::ReadBuffer() {
	Message ret = ptr_[READ]->front();
	ptr_[READ]->pop();
	return ret;
}

int DoubleBuffer::GetSize() {
	return ptr_[READ]->size();
}

} // namespace deulee
