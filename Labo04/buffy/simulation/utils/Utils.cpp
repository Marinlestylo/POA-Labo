//
// Created by Lazar on 26.05.2022.
//
#include "Utils.hpp"
#include <chrono>

using namespace std;

unsigned Utils::random(unsigned max) {
   static mt19937 engine((unsigned int)chrono::system_clock::now().time_since_epoch().count());
   uniform_int_distribution<unsigned> distribution(0, max - 1);
   return distribution(engine);
}