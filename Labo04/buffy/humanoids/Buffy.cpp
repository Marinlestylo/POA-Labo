/**
 * Classe représentant Buffy, la chasseuse de vampire !
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Buffy.hpp"
#include "../simulation/Field.hpp"
#include "../actions/MoveAction.hpp"
#include "../actions/KillAction.hpp"

Buffy::Buffy(int x, int y) : Humanoid(x, y) {
}

void Buffy::setAction(const Field& field) {
   Humanoid::setAction(field);
   if (field.hasVampires()) {
      auto target = field.getNearestHumanoid<Vampire>(getPosition());
      double distance = Position::getEuclideanDistance(getPosition(), target->getPosition());
      if (distance > 1) {
         action = new MoveAction(this, target, 2);
      } else {
         action = new KillAction(this, target);
      }
   } else {
      action = new MoveAction(this, nullptr, 1);
   }
}
