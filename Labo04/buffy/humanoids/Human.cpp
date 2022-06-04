//
// Created by Lazar on 19.05.2022.
//

#include "Human.hpp"
#include "../simulation/actions/MoveAction.hpp"

Human::Human(int x, int y) : Humanoid(x, y) {
}

void Human::setAction(const Field& field) {
   if (action != nullptr) {
      delete action;
      action = nullptr;
   }
   action = new MoveAction(this, nullptr, 1);
}

Humanoid::Identifier Human::getIdentifier() const {
   return Humanoid::HUMAN;
}

