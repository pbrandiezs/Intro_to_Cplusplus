cmake_minimum_required(VERSION 3.25)
project(Intro_to_CPlusPlus)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake to build the multi-file project in the Ch5 folder
add_subdirectory(Ch1-4)
add_subdirectory(Ch5)