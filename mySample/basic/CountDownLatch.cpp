//
// Created by bong on 24. 8. 22.
//

#include "CountDownLatch.h"

CountDownLatch::CountDownLatch(int count):
count_(count), mutex_(){

}

void CountDownLatch::wait() {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [this](){
        return count_ == 0;
    });
}

void CountDownLatch::countDown() {
    std::unique_lock<std::mutex> lock(mutex_);

    if(count_ > 0){
        --count_;
    }

    if(count_ == 0) {
        cv_.notify_all();
    }
}

int CountDownLatch::getCount() const {
    return count_;
}
