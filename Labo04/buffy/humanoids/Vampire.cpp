//
// Created by Lazar on 26.05.2022.
//
#include "Vampire.hpp"
#include "../simulation/Field.hpp"
#include "../simulation/actions/MoveAction.hpp"
#include "../simulation/actions/KillAction.hpp"
#include "../simulation/actions/TransformAction.hpp"
#include "../simulation/utils/Utils.hpp"

Vampire::Vampire(unsigned int posX, unsigned int posY) : Humanoid(posX, posY) {
}

void Vampire::setAction(const Field& field) {
   if (action != nullptr) {
      delete action;
      action = nullptr;
   }
   if (field.getNbHumans()) {
      auto target = field.getNearestHumanoid(this, Identifier::HUMAN);
      double distance = Utils::getEuclideanDistance(this, target);
      if (distance > 1) {
         action = new MoveAction(this, nullptr, 1);
      } else {
         if (Utils::random(2)) {
            action = new KillAction(this, target);
         } else {
            action = new TransformAction(this, target);
         }
      }
   } else {
      action = new MoveAction(this, nullptr, 0);
   }
}

Humanoid::Identifier Vampire::getIdentifier() const {
   return Humanoid::VAMPIRE;
}

