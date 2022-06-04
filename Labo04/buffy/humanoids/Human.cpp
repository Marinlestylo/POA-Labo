//
// Created by Lazar on 19.05.2022.
//

#include "Human.hpp"
#include "../simulation/actions/MoveAction.hpp"

Human::Human(unsigned int posX, unsigned int posY) : Humanoid(posX, posY) {
}

void Human::setAction(const Field& field) {
   if (action != nullptr) {
      delete action;
      action = nullptr;
   }
   action = new MoveAction(this, 1);
}

char Human::getIdentifier() const {
   return 'h';
}

char Human::getHuntedIdentifier() const {
   return 'h';
}