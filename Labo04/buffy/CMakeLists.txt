cmake_minimum_required(VERSION 3.20)
project(buffy)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(buffy main.cpp humanoids/Humanoid.hpp humanoids/Buffy.hpp
        humanoids/Human.hpp humanoids/Vampire.hpp simulation/Action.hpp
        simulation/Field.hpp simulation/Field.cpp humanoids/Humanoid.cpp
        humanoids/Human.cpp displayer.cpp displayer.hpp)
