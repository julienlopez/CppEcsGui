cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE SOURCE_FILES ./*)
add_library(LibGui ${SOURCE_FILES})