cmake_minimum_required(VERSION 3.10)
project(cpp_threads_basico CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)
add_executable(threads src/main.cpp)
target_link_libraries(threads Threads::Threads)

add_executable(hello src/hello.cpp)
target_link_libraries(hello Threads::Threads)

add_executable(Practica3_1 src/Practica3_1/Practica3_1.cpp)
target_link_libraries(Practica3_1 Threads::Threads)
