cmake_minimum_required(VERSION 3.9)
project(TestAddition)

set(CMAKE_CXX_STANDARD 11)

# add the subdirectory containing the CMakeLists.txt for the library
add_subdirectory (src)
include_directories ("${PROJECT_SOURCE_DIR}/src")

add_subdirectory (lib/googletest-master)
include_directories ("lib/googletest-master/googletest/include")
include_directories ("lib/googletest-master/googlemock/include")

add_executable(TestAddition test/tests.cpp)
target_link_libraries (TestAddition src)
target_link_libraries (TestAddition gtest gtest_main)

enable_testing()

add_test (A TestAddition)

project(Main)
set(CMAKE_CXX_STANDARD 11)
add_executable(Main main.cpp main.cpp)
target_link_libraries (Main src)