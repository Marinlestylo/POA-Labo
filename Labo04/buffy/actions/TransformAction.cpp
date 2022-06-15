/**
 * Classe représentant une action qui transforme un humanoïde en vampire
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "TransformAction.hpp"
#include "../simulation/Field.hpp"

TransformAction::TransformAction(Humanoid* target) : Action(target) {
}

void TransformAction::execute(Field& f) {
   if (getTarget()->isAlive()) {
      getTarget()->setAlive(false);
      f.decreasePopulation(getTarget());
      f.addVampire(new Vampire(getTarget()->getPosition().getX(), getTarget()->getPosition().getY()));
   }
}
