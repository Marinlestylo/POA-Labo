/**
 * Classe représentant un humain
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Human.hpp"
#include "../actions/MoveAction.hpp"

Human::Human(int x, int y) : Humanoid(x, y) {
}

void Human::setAction(const Field& field) {
   Humanoid::setAction(field);
   Humanoid::setAction(new MoveAction(this, nullptr, 1));
}

char Human::getSymbol() const {
   return 'h';
}
