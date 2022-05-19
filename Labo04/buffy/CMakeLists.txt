cmake_minimum_required(VERSION 3.20)
project(buffy)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(buffy main.cpp humanoids/Humanoid.hpp humanoids/Buffy.hpp humanoids/Human.hpp humanoids/Vampire.hpp Action.hpp Field.hpp Field.cpp humanoids/Humanoid.cpp)
