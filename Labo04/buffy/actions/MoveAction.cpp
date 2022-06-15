/**
 * Classe représentant une action déplaçant un humanoïde aléatoirement ou vers une cible
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "MoveAction.hpp"
#include "../simulation/Field.hpp"

MoveAction::MoveAction(Humanoid& actionMaker, Humanoid* target, unsigned step)
   : Action(target), actionMaker(actionMaker), step(step), currentX(0), currentY(0) {
   if (target != nullptr) {
      currentX = target->getPosition().getX();
      currentY = target->getPosition().getY();
   }
}

void MoveAction::execute(Field& f) {
   if (step != 0) {
      if (getTarget() != nullptr) {
         Position targetPosition(currentX, currentY);
         actionMaker.getPosition().setDirectedPosition(targetPosition, (int)step);
      } else {
         actionMaker.getPosition().setRandomPosition((int)f.getWidth(), (int)f.getHeight());
      }
   }
}
