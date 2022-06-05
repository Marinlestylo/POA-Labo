/**
 * Enum représentant les directions possibles d'un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

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

const Direction& Direction::get(unsigned index) {
   if (index >= COUNT) {
      throw std::out_of_range("Erreur: L'index est trop grand");
   }
   return *DIRECTIONS[index];
}

unsigned Direction::size() {
   return COUNT;
}

int Direction::getX() const {
   return x;
}

int Direction::getY() const {
   return y;
}

Direction::Direction(int x, int y) {
   this->x = x;
   this->y = y;
   COUNT++;
}