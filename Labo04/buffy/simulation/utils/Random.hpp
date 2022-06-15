#ifndef BUFFY_RANDOM_HPP
#define BUFFY_RANDOM_HPP

#include <string>
#include <random>
#include "../../humanoids/Humanoid.hpp"

/**
 * Classe helper générant des nombres aléatoires
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Random {
public:
   /**
    * Retourne un entier aléatoire entre 0 et la valeur maximale non-comprise
    * @param max Valeur maximale
    * @return un entier aléatoire entre 0 et la valeur maximale non-comprise
    */
   static unsigned random(unsigned max);

   /**
    * Constructeur de copie inaccessible
    */
   Random(Random& other) = delete;

   /**
    * Opérateur d'affectation inaccessible
    */
   void operator=(Random& other) = delete;

private:
   /**
    * Constructeur de base privé
    */
   Random() = default;

   static std::mt19937 engine;
};

#endif //BUFFY_RANDOM_HPP
