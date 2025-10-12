cmake_minimum_required(VERSION 3.10)

project(lnbdc LANGUAGES C)

set(CMAKE_C_STANDARD 17)

add_library(dc STATIC src/lnbdc.c)

add_executable(lnbdc src/main.c)
target_link_libraries(lnbdc dc m)
