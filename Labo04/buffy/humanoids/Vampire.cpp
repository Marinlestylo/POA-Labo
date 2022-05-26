//
// Created by Lazar on 26.05.2022.
//
#include "Vampire.hpp"

Vampire::Vampire(unsigned int posX, unsigned int posY) : Humanoid(posX, posY) {
}


void Vampire::setAction(const Field& field) {

}

void Vampire::executeAction(const Field& field) {

}

char Vampire::getIdentifier() const {
   return 'V';
}