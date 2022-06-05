/**
 * Classe représentant une position dans le field
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include <cmath>
#include "Direction.hpp"
#include "Random.hpp"

int Position::getEuclideanDistance(Position& from, Position& to) {
   double first = abs((from.getX() - to.getX()));
   double second = abs((from.getY() - to.getY()));
   return int(round(hypot(first, second)));
}

Position::Position(int x, int y) : x(x), y(y) {
}

int Position::getX() const {
   return x;
}

int Position::getY() const {
   return y;
}

void Position::setRandomPosition(int maxX, int maxY) {
   bool correctlySetted = false;
   int newX, newY;
   while (!correctlySetted) {
      auto& direction = Direction::get(Random::random(Direction::size()));
      newX = x + direction.getX();
      newY = y + direction.getY();

      if (newX >= 0 && newY >= 0 && newX < maxX && newY < maxY) {
         x = newX;
         y = newY;
         correctlySetted = true;
      }
   }
}

void Position::setDirectedPosition(Position& target, int step) {
   int newX = x, newY = y;

   for (int i = 0; i < step; i++) {
      int dirX = target.getX() - newX;
      int dirY = target.getY() - newY;

      dirX = dirX == 0 ? 0 : dirX / (abs(dirX));
      dirY = dirY == 0 ? 0 : dirY / (abs(dirY));

      newX += dirX;
      newY += dirY;
   }
   x = newX;
   y = newY;
}
