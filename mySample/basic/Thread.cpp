//
// Created by bong on 24. 8. 21.
//

#include "Thread.h"
#include <cassert>
#include <utility>

#include <unistd.h>
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <linux/unistd.h>
#include <iostream>
#include <memory>

#include "CurrentThread.h"

using namespace std;

namespace detail {
    pid_t getId(){
        return static_cast<pid_t>(::syscall(SYS_gettid));
    }
}

void CurrentThread::cacheTid(){
    if (t_cachedTid == 0)
    {
        t_cachedTid = detail::getId();
        t_tidStringLength = snprintf(t_tidString, sizeof t_tidString, "%5d ", t_cachedTid);
    }
}

struct ThreadData
{
    ThreadFunc func_;
    std::string name_;
    pid_t& tid_;
    //CountDownLatch* latch_;

    ThreadData(ThreadFunc func,
               std::string name,
               pid_t& tid)
            : func_(std::move(func)),
              name_(std::move(name)),
              tid_(tid)
    { }

    void runInThread() const
    {
        tid_ = CurrentThread::tid();
        //tid_ = nullptr;
        //latch_->countDown();
        //latch_ = NULL;

        CurrentThread::t_threadName = name_.empty() ? "Thread" : name_.c_str();
        ::prctl(PR_SET_NAME, CurrentThread::t_threadName);

        try
        {
            func_();
            CurrentThread::t_threadName = "finished";
        }
        catch (const std::exception& ex)
        {
            CurrentThread::t_threadName = "crashed";
            fprintf(stderr, "exception caught in Thread %s\n", name_.c_str());
            fprintf(stderr, "reason: %s\n", ex.what());
            //fprintf(stderr, "stack trace: %s\n", ex.stackTrace());
            abort();
        }
        catch (const std::exception& ex)
        {
            CurrentThread::t_threadName = "crashed";
            fprintf(stderr, "exception caught in Thread %s\n", name_.c_str());
            fprintf(stderr, "reason: %s\n", ex.what());
            abort();
        }
        catch (...)
        {
            CurrentThread::t_threadName = "crashed";
            fprintf(stderr, "unknown exception caught in Thread %s\n", name_.c_str());
            throw; // rethrow
        }
    }
};

std::atomic<int32_t> Thread::numCreated_;

Thread::Thread(ThreadFunc func, std::string name)
        : started_(false),
          joined_(false),
          tid_(0),
          threadId_(),
          func_(std::move(func)),
          name_(std::move(name)){

    int num = numCreated_.fetch_add(1);
    if (name_.empty())
    {
        char buf[32];
        snprintf(buf, sizeof buf, "Thread%d", num);
        name_ = buf;
    }
}


void Thread::start() {
    assert(!started_);

    started_ = true;
    auto data = std::make_shared<ThreadData>(func_, name_, tid_);
    t_ = std::thread([data, this](){
        data->runInThread();
    });

    assert(tid_ > 0);
}

Thread::~Thread() {
    if (started_ && !joined_)
    {
       if(t_.joinable()){
           t_.detach();
       }
    }
}

int Thread::join() {
    assert(started_);
    assert(!joined_);
    joined_ = true;
    t_.join();

    return 0;
}

const thread::id &Thread::getTid() const {
    return threadId_;
}


