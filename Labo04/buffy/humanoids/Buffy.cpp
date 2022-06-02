//
// Created by Lazar on 26.05.2022.
//
#include "Buffy.hpp"
#include "../simulation/actions/MoveAction.hpp"

Buffy::Buffy(unsigned int posX, unsigned int posY) : Humanoid(posX, posY) {
}

void Buffy::setAction(const Field& field) {
if (action != nullptr)
      delete action;

   action = new MoveAction(this, 2);
}

char Buffy::getIdentifier() const {
   return 'B';
}

