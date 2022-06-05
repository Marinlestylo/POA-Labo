/**
 * Classe helper générant des nombres aléatoires
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Random.hpp"
#include <chrono>

using namespace std;

unsigned Random::random(unsigned max) {
   static mt19937 engine((unsigned int)chrono::system_clock::now().time_since_epoch().count());
   uniform_int_distribution<unsigned> distribution(0, max - 1);
   return distribution(engine);
}