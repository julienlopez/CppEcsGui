cmake_minimum_required(VERSION 3.10)

include_directories("${PROJECT_SOURCE_DIR}/3rd_party/catch")

add_subdirectory(ecs_unit_tests)
add_subdirectory(gui_unit_tests)
