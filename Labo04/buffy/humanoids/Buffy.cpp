//
// Created by Lazar on 26.05.2022.
//
#include "Buffy.hpp"
#include "../simulation/Field.hpp"
#include "../simulation/actions/MoveAction.hpp"
#include "../simulation/actions/KillAction.hpp"
#include "../simulation/utils/Utils.hpp"

Buffy::Buffy(unsigned int posX, unsigned int posY) : Humanoid(posX, posY) {
}

void Buffy::setAction(const Field& field) {
   // TODO Kill action
   if (action != nullptr) {
      delete action;
      action = nullptr;
   }
   if (field.getNbVampires()) {
      auto target = field.getNearestHumanoid(this, Identifier::VAMPIRE);
      double distance = Utils::getEuclideanDistance(this, target);
      if (distance > 1) {
         action = new MoveAction(this, 1);
      } else {
         action = new KillAction(this, target);
      }
   } else {
      action = new MoveAction(this, 2);
   }
}

Humanoid::Identifier Buffy::getIdentifier() const {
   return Humanoid::BUFFY;
}

