cmake_minimum_required(VERSION 3.16)
project(authntf C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES "source/*.c" "source/**/*.c")

add_executable(authntf ${SOURCES} source/main.c)

target_include_directories(authntf PRIVATE include)