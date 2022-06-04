//
// Created by Lazar on 26.05.2022.
//
#include "Vampire.hpp"
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
      auto target = field.getNearestHumanoid(this, getHuntedIdentifier());
      double distance = Utils::getEuclideanDistance(this, target);
      if (distance > 1) {
         action = new MoveAction(this, 1);
      } else {
         if (Utils::random() % 2) {
            action = new KillAction(this, target);
         } else {
            action = new TransformAction(this, target);
         }
      }
   } else {
      action = new MoveAction(this, 0);
   }
}

char Vampire::getIdentifier() const {
   return 'V';
}

char Vampire::getHuntedIdentifier() const {
   return 'h';
}
