cmake_minimum_required(VERSION 3.9)
project(bigint)

set(CMAKE_CXX_STANDARD 11)

add_executable(bigint main.cpp BigInt.cpp BigInt.h)