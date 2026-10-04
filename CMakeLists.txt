cmake_minimum_required(VERSION 3.10)
project(cpp_threads_basico CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Threads REQUIRED)

foreach(nombre primer_contacto Practica3_1 Practica3_2 Practica3_3)
    add_executable(${nombre} src/${nombre}.cpp)
    target_link_libraries(${nombre} Threads::Threads)
endforeach()
