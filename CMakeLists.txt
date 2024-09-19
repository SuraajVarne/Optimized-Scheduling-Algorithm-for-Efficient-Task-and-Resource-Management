cmake_minimum_required(VERSION 3.10)
project(SchedulingAlgorithm)

set(CMAKE_CXX_STANDARD 17)

# Add executable
add_executable(scheduling_algorithm main.cpp algorithm.cpp)
