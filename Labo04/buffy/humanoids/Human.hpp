#ifndef BUFFY_HUMAN_HPP
#define BUFFY_HUMAN_HPP

#include "Humanoid.hpp"

/**
 * Classe représentant un humain
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Human : public Humanoid {
public:
   /**
    * Constructeur de base
    * @param x Position sur l'axe des x
    * @param y Position sur l'axe des y
    */
   Human(int x, int y);

   void setAction(const Field& field) override;
};

#endif //BUFFY_HUMAN_HPP
