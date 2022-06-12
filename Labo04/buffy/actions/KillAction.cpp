/**
 * Classe représentant une action qui tue un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "KillAction.hpp"
#include "../simulation/Field.hpp"

KillAction::KillAction(Humanoid* actionMaker, Humanoid* target) : Action(actionMaker, target) {
}

void KillAction::execute(Field& f) {
   if (target->isAlive()) {
      target->setAlive(false);
      f.decreasePopulation(target);
   }
}
