add_library(basic
        Thread.cpp
        CurrentThread.cpp
        CountDownLatch.cpp
        Nocopyable.cpp

)

set(CMAKE_CXX_FLAGS -pthread)

add_subdirectory(test)