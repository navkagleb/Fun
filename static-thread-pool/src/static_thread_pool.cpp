#include "static_thread_pool.hpp"

#include <iostream>

namespace ng {

StaticThreadPool::StaticThreadPool(size_t workers) {
  StartWorkerThreads(workers);
}

StaticThreadPool::~StaticThreadPool() {
  assert(workers_.empty());
}

void StaticThreadPool::Submit(Task task) {
  tasks_.Put(std::move(task));
}

void StaticThreadPool::Join() {
  for (auto& worker : workers_) {
    tasks_.Put({});
  }

  for (auto& worker : workers_) {
    worker.join();
  }

  workers_.clear();
}

void StaticThreadPool::StartWorkerThreads(size_t count) {
  workers_.reserve(count);

  for (size_t i = 0; i < count; ++i) {
    workers_.emplace_back([this] {
      WorkerRoutine();
    });
  }
}

void StaticThreadPool::WorkerRoutine() {
  while (true) {
    if (auto task = tasks_.Take(); !task) {
      break;
    } else {
      task();
    }
  }
}

} // namespace ng