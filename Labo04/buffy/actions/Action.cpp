/**
 * Classe représentant une action effectuée par un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Action.hpp"

Action::Action(Humanoid* target) : target(target) {
}

Humanoid* Action::getTarget() const {
   return target;
}
