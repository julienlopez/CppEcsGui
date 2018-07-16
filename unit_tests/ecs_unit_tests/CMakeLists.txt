cmake_minimum_required(VERSION 3.10)

include_directories(".")

file(GLOB_RECURSE SOURCE_FILES ./*)
add_executable(ecs_unit_tests ${SOURCE_FILES})

target_link_libraries(LibEcs)
