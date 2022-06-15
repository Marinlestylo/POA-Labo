/**
 * Classe représentant une action qui tue un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "KillAction.hpp"
#include "../simulation/Field.hpp"

KillAction::KillAction(Humanoid* target) : Action(target) {
}

void KillAction::execute(Field& f) {
   if (getTarget()->isAlive()) {
      getTarget()->setAlive(false);
      f.decreasePopulation(getTarget());
   }
}
