#include <iostream>

#include "static_thread_pool.hpp"

int main() {
  ng::StaticThreadPool thread_pool(4);
  int shared_variable = 0;

  for (int i = 0; i < 106003; ++i) {
    thread_pool.Submit([&] {
      ++shared_variable;
    });
  }

  thread_pool.Join();

  std::cout << "shared_variable: " << shared_variable << std::endl;
}
