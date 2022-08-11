cmake_minimum_required(VERSION 3.0.0)

project(CodingPlayground)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
add_definitions(-DCXX11)
#add_definitions(-DCXX17)

add_subdirectory(DesignPatterns)
add_subdirectory(DSA_Exercises)
add_subdirectory(ExperimentalCode)