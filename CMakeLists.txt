cmake_minimum_required(VERSION 3.21)
project(app1_grupo6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(app1_grupo6
        archivo.c
        archivo.h
        inventario.csv
        libros.c
        libros.h
        main.c
        main.exe
        README.md
        "Tarea 1.pdf"
        test.exe)
