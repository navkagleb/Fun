#pragma once

#include <vector>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "task.hpp"
#include "unbounded_blocking_queue.hpp"

namespace ng {

class StaticThreadPool {
 public:
  explicit StaticThreadPool(size_t workers);
  ~StaticThreadPool();

  void Submit(Task task);
  void Join();

 private:
  void StartWorkerThreads(size_t count);
  void WorkerRoutine();

 private:
  std::vector<std::thread> workers_;
  UnboundedBlockingQueue<Task> tasks_;
};

} // namespace ng