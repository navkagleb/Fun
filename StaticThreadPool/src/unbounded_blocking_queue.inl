#include "unbounded_blocking_queue.hpp"

namespace ng {

template <typename T>
void UnboundedBlockingQueue<T>::Put(T value) {
  std::lock_guard guard(mutex_);
  buffer_.emplace_back(std::move(value));
  not_empty_.notify_one();
}

template <typename T>
T UnboundedBlockingQueue<T>::Take() {
  std::unique_lock lock(mutex_);

  while (buffer_.empty()) {
    not_empty_.wait(lock);
  }

  return TakeLocked();
}

template <typename T>
T UnboundedBlockingQueue<T>::TakeLocked() {
  assert(!buffer_.empty());

  T front = std::move(buffer_.front());
  buffer_.pop_front();
  return front;
}

} // namespace ng