//
// Created by Lazar on 04.06.2022.
//

#include <cmath>
#include "Position.hpp"
#include "Direction.hpp"
#include "Utils.hpp"

Position::Position(int x, int y) : x(x), y(y) {
}

int Position::getEuclideanDistance(Position& from, Position& to) {
   double first = abs((from.getX() - to.getX()));
   double second = abs((from.getY() - to.getY()));
   return int(round(hypot(first, second)));
}

int Position::getX() const {
   return x;
}

void Position::setX(int x) {
   this->x = x;
}

int Position::getY() const {
   return y;
}

void Position::setY(int y) {
   this->y = y;
}

void Position::setRandomPosition(int maxX, int maxY) {
   bool correctlySetted = false;
   int newX, newY;
   while (!correctlySetted) {
      auto& direction = Direction::get(Utils::random(Direction::size()));
      newX = x + direction.getX();
      newY = y + direction.getY();

      if (newX >= 0 && newY >= 0 && newX < maxX && newY < maxY) {
         x = newX;
         y = newY;
         correctlySetted = true;
      }
   }
}

void Position::setDirectedPosition(Position& target, int step, int maxX, int maxY) {
   int newX = x, newY = y;

   for (int i = 0; i < step; i++) {
      int dirX = target.getX() - newX;
      int dirY = target.getY() - newY;

      dirX = dirX == 0 ? 0 : dirX / (abs(dirX));
      dirY = dirY == 0 ? 0 : dirY / (abs(dirY));

      newX += dirX;
      newY += dirY;
   }
   newY < 0 ? newY = 0 : newY;
   newY >= maxY ? newY = maxY - 1 : newY;
   newX < 0 ? newX = 0 : newX;
   newX >= maxX ? newX = maxX - 1 : newX;

   x = newX;
   y = newY;
}
