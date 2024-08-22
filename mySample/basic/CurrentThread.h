//
// Created by bong on 24. 8. 22.
//

#ifndef MULTI_THREADING_CURRENTTHREAD_H
#define MULTI_THREADING_CURRENTTHREAD_H

#include <cstdint>
#include <string>

namespace CurrentThread{
    class CurrentThread {

    };

    // internal
    extern __thread int t_cachedTid;
    extern __thread char t_tidString[32];
    extern __thread int t_tidStringLength;
    extern __thread const char* t_threadName;
    void cacheTid();

    inline int tid() {
        if (__builtin_expect(t_cachedTid == 0, 0))
        {
            cacheTid();
        }
        return t_cachedTid;
    }

    inline const char* tidString() // for logging
    {
        return t_tidString;
    }

    inline int tidStringLength() // for logging
    {
        return t_tidStringLength;
    }

    inline const char* name()
    {
        return t_threadName;
    }

    bool isMainThread();

    std::string stackTrace(bool demangle);

}



#endif //MULTI_THREADING_CURRENTTHREAD_H
