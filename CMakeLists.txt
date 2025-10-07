cmake_minimum_required(VERSION 3.10)

project(lnbd)

add_executable(app src/main.c)

target_link_libraries(app m)
