#ifndef BUFFY_VAMPIRE_HPP
#define BUFFY_VAMPIRE_HPP

#include "Humanoid.hpp"

/**
 * Classe représentant un vampire
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Vampire : public Humanoid {
public:
   /**
    * Constructeur de base
    * @param x Position sur l'axe des x
    * @param y Position sur l'axe des y
    */
   Vampire(int x, int y);

   void setAction(const Field& field) override;

   char getSymbol() const override;
};

#endif //BUFFY_VAMPIRE_HPP
