cmake_minimum_required(VERSION 3.20)
project(Labo1)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Labo1 main.cpp ship.cpp ship.hpp squadron.cpp squadron.hpp tieHunter.cpp tieHunter.hpp tieInterceptor.cpp tieInterceptor.hpp shuttle.cpp shuttle.hpp dreadnought.cpp dreadnought.hpp transporter.cpp transporter.hpp shipCharacteristic.cpp shipCharacteristic.hpp transporterCharacteristic.cpp transporterCharacteristic.hpp)
