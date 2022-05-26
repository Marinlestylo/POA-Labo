//
// Created by Lazar on 26.05.2022.
//
#include "Utils.hpp"
#include <random>
#include <chrono>

using namespace std;

unsigned Utils::Random(unsigned max) {
   static std::mt19937 engine((unsigned int)chrono::system_clock::now().time_since_epoch().count());
   static uniform_int_distribution<unsigned> distribution(0, max - 1);
   return distribution(engine);
}

