#ifndef BUFFY_BUFFY_HPP
#define BUFFY_BUFFY_HPP

#include "Humanoid.hpp"

/**
 * Classe représentant Buffy, la chasseuse de vampire !
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Buffy : public Humanoid {
public:
   /**
    * Constructeur de base
    * @param x Position sur l'axe des x
    * @param y Position sur l'axe des y
    */
   Buffy(int x, int y);

   void setAction(const Field& field) override;

   Identifier getIdentifier() const override;
};

#endif //BUFFY_BUFFY_HPP