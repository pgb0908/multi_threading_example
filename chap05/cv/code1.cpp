#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });  // 조건이 될 때까지 대기 (CPU 사용 안 함)
    std::cout << std::this_thread::get_id() << " Work starts!" << std::endl;
}

int main() {
    std::thread t(worker);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << std::this_thread::get_id() <<  " Main Starts" << std::endl;
    {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << std::this_thread::get_id() <<  " Main: lock acquire" << std::endl;
        ready = true;
    }
    cv.notify_one();  // worker 깨우기
    t.join();
}
