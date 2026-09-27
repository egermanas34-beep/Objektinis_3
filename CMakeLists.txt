cmake_minimum_required(VERSION 3.14)

project(VectorProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main executable
add_executable(StudentuSistema 
    src/main.cpp
    src/studentas.cpp
    src/papildomos_funkcijos.cpp
    src/tyrimai.cpp
    src/generavimas.cpp
    src/ived_isved.cpp
    
    )
target_include_directories(StudentuSistema PRIVATE include)

# Testing support
enable_testing()

# Add local googletest directory
add_subdirectory(googletest)

add_subdirectory(tests)