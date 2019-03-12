cmake_minimum_required (VERSION 3.13)
project (tinyraytracer)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories (include)

set (CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic")

set (SOURCES src/tinyraytracer.cpp)
add_executable (tinyraytracer ${SOURCES})
