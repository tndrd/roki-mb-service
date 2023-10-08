cmake_minimum_required(VERSION 3.0)
project(roki-mb-service)

add_library(MbService src/MbService.cpp src/MbMessages.cpp)
target_include_directories(MbService PUBLIC inc/)