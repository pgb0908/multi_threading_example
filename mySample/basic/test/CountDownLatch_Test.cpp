//
// Created by bong on 24. 8. 22.
//

#include "../CountDownLatch.h"
#include <iostream>
#include "../Thread.h"

const int kCount = 1;

void worker() {
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
}

int main() {
    const int threadCount = 1;
    CountDownLatch latch(threadCount);

    std::vector<std::shared_ptr<Thread>> threads;
    for (int i = 0; i < threadCount; ++i) {
        auto t1 = std::make_shared<Thread>(worker);
        threads.push_back(t1);
    }

    latch.wait(); // Wait for all threads to finish
    std::cout << "All workers have finished. Proceeding...\n";

    for (auto& t : threads) {
        t->join();
    }

    return 0;
}