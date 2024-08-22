//
// Created by bong on 24. 8. 21.
//

#include "Thread.h"
#include "CurrentThread.h"
#include <iostream>

#include <string>
#include <unistd.h>

void threadFunc()
{
    printf("printed tid=%d\n", CurrentThread::tid());
    std::cout << "t1 is main thread?? : " << (CurrentThread::isMainThread() ? "yes": "no") << std::endl;
}

void threadFunc2(int x)
{
    printf("tid=%d, x=%d\n", CurrentThread::tid(), x);
}

class Foo
{
public:
    explicit Foo(double x)
            : x_(x)
    {
    }

    void memberFunc()
    {
        printf("tid=%d, Foo::x_=%f\n", CurrentThread::tid(), x_);
    }

    void memberFunc2(const std::string& text)
    {
        printf("tid=%d, Foo::x_=%f, text=%s\n", CurrentThread::tid(), x_, text.c_str());
    }

private:
    double x_;
};

int main() {

    printf("pid=%d, tid=%d\n", ::getpid(), CurrentThread::tid());

    Thread t1(threadFunc);
    t1.start();
    printf("t1.tid=%d\n", t1.tid());
    t1.join();
    printf("after t1.tid=%d\n", t1.tid());

    std::cout << "is main thread?? : " << (CurrentThread::isMainThread() ? "yes": "no") << std::endl;

/*    Thread t2(std::bind(threadFunc2, 42),
                     "thread for free function with argument");
    t2.start();
    printf("t2.tid=%d\n", t2.tid());
    t2.join();

    Foo foo(87.53);
    Thread t3(std::bind(&Foo::memberFunc, &foo),
                     "thread for member function without argument");
    t3.start();
    t3.join();*/

    return 0;
}