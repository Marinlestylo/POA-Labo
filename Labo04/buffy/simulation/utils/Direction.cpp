//
// Created by Lazar on 04.06.2022.
//

#include <stdexcept>
#include "Direction.hpp"

const Direction Direction::LEFT_UP(-1, -1);
const Direction Direction::UP(0, -1);
const Direction Direction::RIGHT_UP(1, -1);
const Direction Direction::LEFT(-1, 0);
const Direction Direction::RIGHT(1, 0);
const Direction Direction::LEFT_DOWN(-1, 1);
const Direction Direction::DOWN(0, 1);
const Direction Direction::RIGHT_DOWN(1, 1);

unsigned Direction::COUNT = 0;

const Direction* Direction::DIRECTIONS[]{
   &LEFT_UP, &UP, &RIGHT_UP, &LEFT, &RIGHT, &LEFT_DOWN, &DOWN, &RIGHT_DOWN
};

Direction::Direction(int x, int y) {
   this->x = x;
   this->y = y;
   COUNT++;
}

unsigned Direction::size() {
   return COUNT;
}

const Direction& Direction::get(unsigned int i) {
   if (i >= COUNT) {
      throw std::out_of_range("Erreur: L'indice est trop grand");
   }
   return *DIRECTIONS[i];
}

int Direction::getX() const {
   return x;
}

int Direction::getY() const {
   return y;
}
