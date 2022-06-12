/**
 * Classe représentant un vampire
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Vampire.hpp"
#include "../simulation/Field.hpp"
#include "../actions/MoveAction.hpp"
#include "../actions/KillAction.hpp"
#include "../actions/TransformAction.hpp"
#include "../simulation/utils/Random.hpp"
#include "Human.hpp"

Vampire::Vampire(int x, int y) : Humanoid(x, y) {
}

void Vampire::setAction(const Field& field) {
   Humanoid::setAction(field);
   if (field.hasHumans()) {
      auto target = field.getNearestHumanoid<Human>(getPosition());
      double distance = Position::getEuclideanDistance(getPosition(), target->getPosition());
      if (distance > 1) {
         action = new MoveAction(this, target, 1);
      } else {
         if (Random::random(2)) {
            action = new KillAction(this, target);
         } else {
            action = new TransformAction(this, target);
         }
      }
   } else {
      action = new MoveAction(this, nullptr, 0);
   }
}

