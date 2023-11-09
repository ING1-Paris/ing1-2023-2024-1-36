cmake_minimum_required(VERSION 3.26)
project(snoopy C)

set(CMAKE_C_STANDARD 23)

add_executable(snoopy main.c
        plateau.c)
