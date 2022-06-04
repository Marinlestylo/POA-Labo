//
// Created by Lazar on 26.05.2022.
//
#include "Utils.hpp"
#include <random>
#include <chrono>

using namespace std;

unsigned Utils::random(unsigned max) {
   static std::mt19937 engine((unsigned int)chrono::system_clock::now().time_since_epoch().count());
   static uniform_int_distribution<unsigned> distribution(0, max - 1);
   return distribution(engine);
}

// TODO: Ca dégage
DisplayType Utils::getDisplayType(const string& type) {
   switch (type[0]) {
      case 'n':
         return DisplayType::NO_DISPLAY;
      case 'c':
      default:
         return DisplayType::CONSOLE;
   }
}

double Utils::getEuclideanDistance(Humanoid* from, Humanoid* to) {
   // TODO : Gros gros refactor de cette immondice
   return (round(hypot(abs(double((int)from->getPosX() - (int)to->getPosX())), abs
      (double((int)from->getPosY() - (int)to->getPosY())))));
}
