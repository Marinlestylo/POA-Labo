//
// Created by Lazar on 19.05.2022.
//
#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "../simulation/actions/Action.hpp"

class Humanoid {
public:
   enum Identifier {
      HUMAN,
      VAMPIRE,
      BUFFY
   };

   Humanoid(unsigned posX, unsigned posY);

   virtual ~Humanoid() = default;

   unsigned getPosX() const;

   unsigned getPosY() const;

   void setPosX(unsigned posX);

   void setPosY(unsigned posY);

   bool isAlive() const;

   void setAlive(bool alive);

   void executeAction(Field& field);

   virtual void setAction(const Field& field) = 0;

   virtual Identifier getIdentifier() const = 0;

protected:
   Action* action;
private:
   bool alive;
   unsigned posX, posY;
};

#endif //BUFFY_HUMANOID_HPP
