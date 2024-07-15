set(CMAKE_CXX_FLAGS -pthread)

add_executable(chap04_main
        main.cpp
        dispatcher.cpp
        request.cpp
        worker.cpp
)


target_link_libraries(chap04_main
)