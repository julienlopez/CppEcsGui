cmake_minimum_required(VERSION 3.10)
project(CppEcsGui)

#include_directories(3rd_party/catch)

include_directories("${PROJECT_SOURCE_DIR}/libs")

add_subdirectory(libs)
add_subdirectory(unit_tests)
