cmake_minimum_required(VERSION 3.8)

# Project definition
project("cosc1337_final_exam")

# Use C++17 and enable warnings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Add subdirectories
add_subdirectory(src)
add_subdirectory(test)

# Enable testing
enable_testing()
