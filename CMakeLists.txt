cmake_minimum_required(VERSION 3.14)

project(VectorProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main executable
add_executable(StudentuSistema main.cpp)
target_include_directories(StudentuSistema PRIVATE ${CMAKE_SOURCE_DIR})

# Testing support
enable_testing()

# Add local googletest directory
add_subdirectory(googletest)

add_subdirectory(tests)