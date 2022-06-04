//
// Created by Lazar on 03.06.2022.
//

#include "TransformAction.hpp"
#include "../../humanoids/Humanoid.hpp"
#include "../../humanoids/Vampire.hpp"

TransformAction::TransformAction(Humanoid* actionMaker, Humanoid* target) : Action(actionMaker),
                                                                            target(target) {
}

void TransformAction::execute(Field& f) {
   if (target->isAlive()) {
      target->setAlive(false);
      f.decreasePopulation(actionMaker->getHuntedIdentifier());
      f.addVampire(new Vampire(target->getPosX(), target->getPosY()));
   }
}
