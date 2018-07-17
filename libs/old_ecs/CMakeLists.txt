cmake_minimum_required(VERSION 3.10)

include_directories(.)

file(GLOB_RECURSE SOURCE_FILES ./*)
add_library(LibEcs ${SOURCE_FILES})