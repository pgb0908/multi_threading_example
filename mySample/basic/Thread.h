//
// Created by bong on 24. 8. 21.
//

#ifndef MULTI_THREADING_THREAD_H
#define MULTI_THREADING_THREAD_H

#include <thread>
#include <string>
#include <functional>
#include <atomic>


using ThreadFunc = std::function<void ()>;

class Thread {
public:
    explicit Thread(ThreadFunc, std::string  name = std::string());
    ~Thread();

    void start();
    int join();

    const std::thread::id &getTid() const;
    pid_t tid() const { return tid_; }

    bool started() const {
        return started_;
    }

private:
    bool started_;
    bool joined_;
    std::thread::id threadId_;
    pid_t tid_;
    std::thread t_;
    ThreadFunc func_;
    std::string name_;


    static std::atomic<int32_t> numCreated_;
};


#endif //MULTI_THREADING_THREAD_H
