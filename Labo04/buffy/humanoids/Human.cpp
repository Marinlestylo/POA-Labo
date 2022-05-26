//
// Created by Lazar on 19.05.2022.
//

#include "Human.hpp"

Human::Human(unsigned int posX, unsigned int posY) : Humanoid(posX, posY) {
}

void Human::setAction(const Field& field) {

}

void Human::executeAction(const Field& field) {

}

char Human::getIdentifier() const {
   return 'h';
}