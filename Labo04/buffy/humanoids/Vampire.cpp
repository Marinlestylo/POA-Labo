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
      if (distance > RANGE) {
         Humanoid::setAction(new MoveAction(*this, target, RANGE));
      } else {
         if (Random::random(2)) {
            Humanoid::setAction(new KillAction(target));
         } else {
            Humanoid::setAction(new TransformAction(target));
         }
      }
   }
}

char Vampire::getSymbol() const {
   return 'V';
}

