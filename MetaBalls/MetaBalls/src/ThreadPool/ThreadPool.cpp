#include "ThreadPool.hpp"

namespace Meta {

    // constructor / destructor
    ThreadPool::ThreadPool(std::size_t count) : m_Stop(false) {
        m_Threads.reserve(count);

        for (std::size_t i = 0; i < m_Threads.capacity(); ++i) {
            m_Threads.emplace_back([&] {
                while (true) {
                    Task task;

                    {
                        std::unique_lock<std::mutex> lock(m_Mutex);

                        m_ConditionVariable.wait(lock, [&] {
                            return m_Stop || !m_Tasks.empty();
                        });

                        if (m_Stop && m_Tasks.empty())
                            break;

                        task = std::move(m_Tasks.front());
                        m_Tasks.pop();
                    }

                    task();
                }
            });
        }
    }

    ThreadPool::~ThreadPool() noexcept {
        {
            std::unique_lock<std::mutex> lock(m_Mutex);
            m_Stop = true;
        }

        m_ConditionVariable.notify_all();

        for (auto& thread : m_Threads)
            thread.join();
    }

} // namespace Meta