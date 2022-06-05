/**
 * Classe représentant Buffy, la chasseuse de vampire !
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Buffy.hpp"
#include "../simulation/Field.hpp"
#include "../simulation/actions/MoveAction.hpp"
#include "../simulation/actions/KillAction.hpp"

Buffy::Buffy(int x, int y) : Humanoid(x, y) {
}

void Buffy::setAction(const Field& field) {
   if (action != nullptr) {
      delete action;
      action = nullptr;
   }
   if (field.hasVampires()) {
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
