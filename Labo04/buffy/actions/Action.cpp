/**
 * Classe représentant une action effectuée par un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Action.hpp"

Action::Action(Humanoid& actionMaker, Humanoid* target) : actionMaker(actionMaker), target
(target) {
}