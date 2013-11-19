#ifndef SCOPEDTHREAD_HPP
#define SCOPEDTHREAD_HPP

#include <thread>
#include <stdexcept>

class ScopedThread
{
    public:
        ScopedThread(std::thread t):
            m_Thread(std::move(t))
        {
            if (!m_Thread.joinable())
                throw std::logic_error("No thread");
        }

        ~ScopedThread()
        {
            m_Thread.join();
        }

        ScopedThread(const ScopedThread&) = delete;
        ScopedThread& operator=(const ScopedThread&) = delete;

    private:
        std::thread m_Thread;
};

#endif // SCOPEDTHREAD_HPP
