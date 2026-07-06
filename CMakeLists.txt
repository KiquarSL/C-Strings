cmake_minimum_required(VERSION 3.28.3)

project(strings LANGUAGES C)
enable_testing()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(strings src/lib.c)
target_include_directories(strings PUBLIC include)

add_subdirectory(tests)