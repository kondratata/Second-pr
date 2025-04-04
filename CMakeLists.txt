cmake_minimum_required(VERSION 3.10)
project(Prak2 C)

set(CMAKE_C_STANDARD 11)

add_executable(pr2 main.c users.c processes.c help.c log.c error_handler.c)
