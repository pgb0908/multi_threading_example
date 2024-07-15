
#[[set(CMAKE_CXX_FLAGS -pthread)]]

find_package(Threads REQUIRED)
add_executable(ch05_test01 main.cpp)

target_link_libraries(ch05_test01 PRIVATE Threads::Threads)