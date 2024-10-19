cmake_minimum_required(VERSION 3.29)
project(BTMoon)

set(CMAKE_CXX_STANDARD 20)

add_executable(BTMoon main.cpp
        device/Device.cpp
        device/Device.h)
