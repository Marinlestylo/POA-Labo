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
      if (distance > RANGE) {
         Humanoid::setAction(new MoveAction(*this, target, 2));
      } else {
         Humanoid::setAction(new KillAction(target));
      }
   } else {
      Humanoid::setAction(new MoveAction(*this, nullptr, RANGE));
   }
}

char Buffy::getSymbol() const {
   return 'B';
}
