//
// Created by Lazar on 19.05.2022.
//

#include "Humanoid.hpp"

Humanoid::Humanoid(int x, int y) : action(nullptr), alive(true), position(x, y) {
}


bool Humanoid::isAlive() const {
   return alive;
}

void Humanoid::setAlive(bool alive) {
   this->alive = alive;
}

Position& Humanoid::getPosition() {
   return position;
}

void Humanoid::executeAction(Field& field) {
   if (action != nullptr) {
      action->execute(field);
   }
}
