
set(CMAKE_CXX_FLAGS -pthread)

find_package(Threads REQUIRED)
add_executable(ch05_test06 code1.cpp)
