cmake_minimum_required(VERSION 3.12)
project(hash_table_in_C C)

set(CMAKE_C_STANDARD 99)

add_executable(hash_table_in_C main.c hash_table.h hash_table.c prime.h prime.c)