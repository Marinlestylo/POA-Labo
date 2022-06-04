//
// Created by Lazar on 19.05.2022.
//

#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "../simulation/actions/Action.hpp"

class Humanoid {
public:
   Humanoid(unsigned posX, unsigned posY);

   virtual ~Humanoid() = default;

   unsigned getPosX() const;

   unsigned getPosY() const;

   void setPosX(unsigned posX);

   void setPosY(unsigned posY);

   void executeAction(Field& field);

   void setAlive(bool alive);

   bool isAlive() const;

   virtual void setAction(const Field& field) = 0;

   // TODO: Utilisation d'enum protected pour cette merde ??

   virtual char getIdentifier() const = 0;

   virtual char getHuntedIdentifier() const = 0;

protected:
   Action* action;
private:
   bool alive;
   unsigned posX, posY;
};

#endif //BUFFY_HUMANOID_HPP
