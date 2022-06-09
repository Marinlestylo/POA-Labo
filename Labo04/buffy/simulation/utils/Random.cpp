/**
 * Classe helper générant des nombres aléatoires
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Random.hpp"
#include <chrono>

using namespace std;

mt19937 Random::engine((unsigned)chrono::system_clock::now().time_since_epoch().count());

unsigned Random::random(unsigned max) {
   uniform_int_distribution<unsigned> distribution(0, max - 1);
   return distribution(engine);
}