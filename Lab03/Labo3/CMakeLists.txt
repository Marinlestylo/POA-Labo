cmake_minimum_required(VERSION 3.20)
project(Labo3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Labo3 main.cpp Characters/person.cpp Characters/person.hpp Containers/bank.cpp Containers/bank.hpp Containers/boat.cpp Containers/boat.hpp controller.cpp controller.hpp Containers/container.cpp Containers/container.hpp Characters/thief.cpp Characters/thief.hpp Characters/dependentPerson.cpp Characters/dependentPerson.hpp Characters/driver.cpp Characters/driver.hpp Characters/boy.cpp Characters/boy.hpp Characters/girl.cpp Characters/girl.hpp)
