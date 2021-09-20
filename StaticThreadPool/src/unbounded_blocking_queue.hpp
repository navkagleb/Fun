#pragma once

#include <deque>
#include <mutex>
#include <condition_variable>
#include <cassert>

namespace ng {

template <typename T>
class UnboundedBlockingQueue {
 public:
  void Put(T value);

  T Take();

 private:
  T TakeLocked();

 private:
  std::deque<T>           buffer_; // Guarded by mutex_
  std::mutex              mutex_;
  std::condition_variable not_empty_;
};

} // namespace ng

#include "unbounded_blocking_queue.inl"