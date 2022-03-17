cmake_minimum_required(VERSION 3.20)
project(Labo1)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Labo1 main.cpp matrix.cpp matrix.hpp operation.hpp add.cpp add.hpp substract.cpp substract.hpp multiply.cpp multiply.hpp utils.cpp utils.hpp)
