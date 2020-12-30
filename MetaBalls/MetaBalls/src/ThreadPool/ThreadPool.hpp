#pragma once

#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>
#include <future>
#include <iostream>

namespace Meta {

    //////////////////////////////////////////////////////////////
    /// HEADER
    //////////////////////////////////////////////////////////////
    class ThreadPool {
    public:
        // Aliases
        using Task = std::function<void()>;

        // Constructor / Destructor
        explicit ThreadPool(std::size_t count);
        virtual ~ThreadPool() noexcept;

        // accessors
        [[nodiscard]] inline bool IsEmpty() { return m_Tasks.empty(); }
        [[nodiscard]] inline std::size_t GetTasksCount() { return m_Tasks.size(); }
        [[nodiscard]] inline std::size_t GetThreadsCount() { return m_Threads.size(); }

        // Public methods
        template <typename T>
        auto Enqueue(T&& task) -> std::future<decltype(task())>;

    private:
        // Member data
        std::vector<std::thread> m_Threads;
        std::condition_variable m_ConditionVariable;
        std::mutex m_Mutex;
        std::queue<Task> m_Tasks;
        bool m_Stop;

    }; // class ThreadPool

    //////////////////////////////////////////////////////////////
    /// SOURCE
    //////////////////////////////////////////////////////////////
    // Public methods
    template <typename T>
    auto ThreadPool::Enqueue(T&& task) -> std::future<decltype(task())> {

        auto wrapper = std::make_shared<std::packaged_task<decltype(task())()>>(std::forward<T>(task));

        {
            std::unique_lock<std::mutex> lock(m_Mutex);
            m_Tasks.emplace([=] { (*wrapper)(); });
        }

        m_ConditionVariable.notify_one();
        return wrapper->get_future();
    }

} // namespace Meta