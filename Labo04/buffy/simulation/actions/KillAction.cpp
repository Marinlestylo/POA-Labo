//
// Created by Lazar on 03.06.2022.
//

#include "KillAction.hpp"
#include "../Field.hpp"
#include "../../humanoids/Humanoid.hpp"

KillAction::KillAction(Humanoid* actionMaker, Humanoid* target)
                                                      : Action(actionMaker), target(target) {
}

void KillAction::execute(Field& f) {
   if (target->isAlive()) {
      target->setAlive(false);
      f.decreasePopulation(target->getIdentifier());
   }
}
