cmake_minimum_required(VERSION 3.10)

project(lnbd LANGUAGES C)

set(CMAKE_C_STANDARD 17)

add_executable(app src/main.c)

target_link_libraries(app m)
