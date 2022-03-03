cmake_minimum_required(VERSION 3.20)
project(Labo1)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Labo1 main.cpp matrix.cpp matrix.h operation.h add.cpp add.h substract.cpp substract.h multiply.cpp multiply.h)
