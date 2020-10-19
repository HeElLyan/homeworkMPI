cmake_minimum_required(VERSION 3.14)
project(homeworkMPI)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/Users/heel/CLionProjects/homeworkMPI/cmake-build-debug/debug")

add_executable(homeworkMPI Task1.cpp Task2.cpp Task3.cpp Task4.cpp Task5.cpp Task6.cpp Task7.cpp Task9.cpp Task10.cpp Task11.cpp Task8.cpp)

find_package(MPI)
if(MPI_CXX_FOUND)
    target_link_libraries(homeworkMPI PUBLIC MPI::MPI_CXX)
endif()