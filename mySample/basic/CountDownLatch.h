//
// Created by bong on 24. 8. 22.
//

#ifndef MULTI_THREADING_COUNTDOWNLATCH_H
#define MULTI_THREADING_COUNTDOWNLATCH_H

#include "NoCopyable.h"
#include <mutex>
#include <condition_variable>

class CountDownLatch : public NoCopyable{
public:
    explicit CountDownLatch(int);

    void wait();

    void countDown();

    int getCount() const;

private:
    std::mutex mutex_;
    std::condition_variable cv_;
    int count_;



};


#endif //MULTI_THREADING_COUNTDOWNLATCH_H
