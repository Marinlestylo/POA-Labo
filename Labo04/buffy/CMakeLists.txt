cmake_minimum_required(VERSION 3.20)
project(buffy)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(buffy main.cpp humanoids/Humanoid.hpp humanoids/Buffy.hpp
        humanoids/Human.hpp humanoids/Vampire.hpp actions/Action.hpp
        simulation/Field.hpp simulation/Field.cpp humanoids/Humanoid.cpp
        humanoids/Human.cpp displayers/Displayer.cpp displayers/Displayer.hpp humanoids/Buffy.cpp humanoids/Vampire.cpp simulation/utils/Random.hpp simulation/utils/Random.cpp displayers/ConsoleDisplayer.cpp displayers/ConsoleDisplayer.hpp simulation/Simulator.cpp simulation/Simulator.hpp actions/MoveAction.hpp actions/MoveAction.cpp actions/KillAction.cpp actions/KillAction.hpp actions/TransformAction.cpp actions/TransformAction.hpp actions/Action.cpp simulation/utils/Position.cpp simulation/utils/Position.hpp simulation/utils/Direction.cpp simulation/utils/Direction.hpp displayers/utils/termcolor.hpp)
