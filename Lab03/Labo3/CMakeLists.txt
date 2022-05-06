cmake_minimum_required(VERSION 3.20)
project(Labo3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Labo3 main.cpp person.cpp person.hpp bank.cpp bank.hpp boat.cpp boat.hpp controller.cpp controller.hpp container.cpp container.hpp thief.cpp thief.hpp dependentPeople.cpp dependentPeople.hpp driver.cpp driver.hpp)
