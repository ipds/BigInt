cmake_minimum_required(VERSION 3.9)
project(bigint)

set(CMAKE_CXX_STANDARD 11)

add_executable(bigint test/main.cpp src/BigInt.cpp src/BigInt.h src/operator_overload.cpp src/addition.cpp src/subtraction.cpp src/conversions.cpp src/constr-get-set.cpp src/multiplication.cpp src/division.cpp)