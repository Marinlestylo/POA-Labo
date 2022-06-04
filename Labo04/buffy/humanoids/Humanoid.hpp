//
// Created by Lazar on 19.05.2022.
//
#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "../simulation/actions/Action.hpp"
#include "../simulation/utils/Position.hpp"

class Humanoid {
public:
   enum Identifier {
      HUMAN,
      VAMPIRE,
      BUFFY
   };

   Humanoid(int x, int y);

   virtual ~Humanoid() = default;

   Position& getPosition();

   bool isAlive() const;

   void setAlive(bool alive);

   void executeAction(Field& field);

   virtual void setAction(const Field& field) = 0;

   virtual Identifier getIdentifier() const = 0;

protected:
   Action* action;
private:
   bool alive;
   Position position;
};

#endif //BUFFY_HUMANOID_HPP
