cmake_minimum_required(VERSION 3.25)
project(Intro_to_CPlusPlus)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find all .cpp files in the directory
file(GLOB CPP_FILES "*.cpp")

# Automatically create a separate executable for every single .cpp file found
foreach(file ${CPP_FILES})
    # Strip the file extension to use as the executable name (e.g., vector_input.cpp -> vector_input)
    get_filename_component(target_name ${file} NAME_WE)
    add_executable(${target_name} ${file})
endforeach()