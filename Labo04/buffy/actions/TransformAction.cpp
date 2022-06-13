/**
 * Classe représentant une action qui transforme un humanoïde en vampire
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "TransformAction.hpp"
#include "../simulation/Field.hpp"

TransformAction::TransformAction(Humanoid& actionMaker, Humanoid* target)
   : Action(actionMaker, target) {
}

void TransformAction::execute(Field& f) {
   if (target->isAlive()) {
      target->setAlive(false);
      f.decreasePopulation(target);
      f.addVampire(new Vampire(target->getPosition().getX(), target->getPosition().getY()));
   }
}
