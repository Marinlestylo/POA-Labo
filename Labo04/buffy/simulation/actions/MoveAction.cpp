//
// Created by Lazar on 02.06.2022.
//
#include "MoveAction.hpp"
#include "../Field.hpp"

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
         actionMaker->getPosition().setDirectedPosition(targetPosition, step,
                                                        f.getWidth(),
                                                        f.getHeight());
      } else {
         actionMaker->getPosition().setRandomPosition(f.getWidth(), f.getHeight());
      }
   }
}

