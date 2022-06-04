//
// Created by Lazar on 26.05.2022.
//
#include "Buffy.hpp"
#include "../simulation/Field.hpp"
#include "../simulation/actions/MoveAction.hpp"
#include "../simulation/actions/KillAction.hpp"
#include "../simulation/utils/Utils.hpp"

Buffy::Buffy(int x, int y) : Humanoid(x, y) {
}

void Buffy::setAction(const Field& field) {
   if (action != nullptr) {
      delete action;
      action = nullptr;
   }
   if (field.getNbVampires()) {
      auto target = field.getNearestHumanoid(getPosition(), Identifier::VAMPIRE);
      int distance = Position::getEuclideanDistance(getPosition(), target->getPosition());
      if (distance > 1) {
         action = new MoveAction(this, target, 2);
      } else {
         action = new KillAction(this, target);
      }
   } else {
      action = new MoveAction(this, nullptr, 1);
   }
}

Humanoid::Identifier Buffy::getIdentifier() const {
   return Humanoid::BUFFY;
}

