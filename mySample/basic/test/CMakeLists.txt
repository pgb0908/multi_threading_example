add_executable(ThreadTest ThreadTest.cpp)
target_link_libraries(ThreadTest basic)

add_executable(cdl_test CountDownLatch_Test.cpp)
target_link_libraries(cdl_test basic)