//
// Created by Lazar on 02.06.2022.
//
#include "MoveAction.hpp"
#include "../Field.hpp"

MoveAction::MoveAction(Humanoid* actionMaker, Humanoid* target, unsigned step)
   : Action(actionMaker, target), step(step) {
}

void MoveAction::execute(Field& f) {
   if  (step != 0) {
      if (target != nullptr) {
         actionMaker->getPosition().setDirectedPosition(target->getPosition(), step, f.getWidth(), f.getHeight());
      } else {
         actionMaker->getPosition().setRandomPosition(f.getWidth(), f.getHeight());
      }
   }
}

