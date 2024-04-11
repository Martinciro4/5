cmake_minimum_required(VERSION 3.28)
project(clase5 C)

set(CMAKE_C_STANDARD 90)

add_executable(clase5 main.c
        semaforos.h
        semaforos.c
        defs.h)
