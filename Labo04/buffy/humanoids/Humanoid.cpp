//
// Created by Lazar on 19.05.2022.
//

#include "Humanoid.hpp"

Humanoid::Humanoid(unsigned posX, unsigned posY) : alive(true), posX(posX), posY(posY),
                                                   action(nullptr) {
}

bool Humanoid::isAlive() const {
   return alive;
}

unsigned Humanoid::getPosX() const {
	return posX;
}

unsigned Humanoid::getPosY() const {
	return posY;
}
