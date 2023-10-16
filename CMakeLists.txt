cmake_minimum_required(VERSION 3.26)
project(CS213_2023_20220912_20220732_20220764_A1_Part1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS213_2023_20220912_20220732_20220764_A1_Part1
        .idea/vcs.xml
        .idea/workspace.xml
        cmake-build-debug/in_images/crowd.bmp
        cmake-build-debug/in_images/elephant.bmp
        cmake-build-debug/in_images/fruit.bmp
        cmake-build-debug/in_images/House.bmp
        cmake-build-debug/in_images/photographer.bmp
        bmplib.cpp
        bmplib.h
        CS213-2023-20220912-20220732-20220764-A1-Part1.cpp.cpp)
