/**
 * Classe abstraite représentant un humanoïde.
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Humanoid.hpp"

Humanoid::Humanoid(int x, int y) : action(nullptr), alive(true), position(x, y) {
}

Humanoid::~Humanoid() {
   delete action;
}

Position& Humanoid::getPosition() {
   return position;
}

bool Humanoid::isAlive() const {
   return alive;
}

void Humanoid::setAlive(bool alive) {
   this->alive = alive;
}

void Humanoid::executeAction(Field& field) {
   if (action != nullptr) {
      action->execute(field);
   }
}

void Humanoid::setAction(const Field& field) {
   if (action != nullptr) {
      delete action;
      action = nullptr;
   }
}
