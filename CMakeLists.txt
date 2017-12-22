cmake_minimum_required(VERSION 3.6)
project(FinalProject)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES BookStore.cpp Book.cpp LinkedList.cpp WaitList.cpp Person.cpp)

add_executable(FinalProject ${SOURCE_FILES})