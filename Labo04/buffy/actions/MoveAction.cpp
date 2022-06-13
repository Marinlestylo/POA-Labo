/**
 * Classe représentant une action déplaçant un humanoïde aléatoirement ou vers une cible
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "MoveAction.hpp"
#include "../simulation/Field.hpp"

// TODO : Refactor currentX & currentY + les casts

MoveAction::MoveAction(Humanoid* actionMaker, Humanoid* target, unsigned step)
   : Action(actionMaker, target), step(step) {
   if (target != nullptr) {
      currentX = target->getPosition().getX();
      currentY = target->getPosition().getY();
   } else {
      currentX = 0;
      currentY = 0;
   }
}

void MoveAction::execute(Field& f) {
   if (step != 0) {
      if (target != nullptr) {
         Position targetPosition(currentX, currentY);
         actionMaker->getPosition().setDirectedPosition(targetPosition, (int)step);
      } else {
         actionMaker->getPosition().setRandomPosition((int)f.getWidth(), (int)f.getHeight());
      }
   }
}
