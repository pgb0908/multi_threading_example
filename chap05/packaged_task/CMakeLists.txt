
set(CMAKE_CXX_FLAGS -pthread)

find_package(Threads REQUIRED)
add_executable(ch05_test08 code1.cpp)
