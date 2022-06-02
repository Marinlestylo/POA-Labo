//
// Created by Lazar on 26.05.2022.
//
#include "Vampire.hpp"
#include "../simulation/actions/MoveAction.hpp"

Vampire::Vampire(unsigned int posX, unsigned int posY) : Humanoid(posX, posY) {
}


void Vampire::setAction(const Field& field) {
   if (action != nullptr)
      delete action;

   action = new MoveAction(this, 0);
}

char Vampire::getIdentifier() const {
   return 'V';
}