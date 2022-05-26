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

   virtual void setAction(const Field& field) = 0;

   virtual void executeAction(const Field& field) = 0;

   virtual char getIdentifier() const = 0;

   bool isAlive() const;

private:
   bool alive;
   unsigned posX, posY;
   Action* action;
};

#endif //BUFFY_HUMANOID_HPP
