cmake_minimum_required(VERSION 3.9)
project(TestAddition)

set(CMAKE_CXX_STANDARD 11)

# add the subdirectory containing the CMakeLists.txt for the library
add_subdirectory (src)
include_directories ("${PROJECT_SOURCE_DIR}/src")

add_executable(TestAddition test/addition_test.cpp)
target_link_libraries (TestAddition src)

enable_testing()

add_test (AdditionComp1 TestAddition 25 25)

set_tests_properties (AdditionComp1
        PROPERTIES PASS_REGULAR_EXPRESSION "25 + 25 = 50")