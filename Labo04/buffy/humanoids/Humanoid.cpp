//
// Created by Lazar on 19.05.2022.
//

#include "Humanoid.hpp"

Humanoid::Humanoid(unsigned posX, unsigned posY) : action(nullptr), alive(true), posX(posX),
                                                   posY(posY) {
}

bool Humanoid::isAlive() const {
   return alive;
}

void Humanoid::setAlive(bool alive) {
   this->alive = alive;
}

unsigned Humanoid::getPosX() const {
   return posX;
}

unsigned Humanoid::getPosY() const {
   return posY;
}

void Humanoid::setPosX(unsigned int posX) {
   this->posX = posX;
}

void Humanoid::setPosY(unsigned int posY) {
   this->posY = posY;
}

void Humanoid::executeAction(Field& field) {
   if (action != nullptr && alive) {
      action->execute(field);
   }
}

// TODO : A refactor
char Humanoid::getHuntedIdentifier() const {
   return 'X';
}
