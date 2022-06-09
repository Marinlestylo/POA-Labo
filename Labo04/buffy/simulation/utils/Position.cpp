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
   std::vector<const Direction*> possibleDirections;
   bool isRestricted = false;

   if (x == 0 || y == 0 || x == maxX - 1 || y == maxY - 1) {
      isRestricted = true;
      for (const Direction* s = *Direction::values();
           s <= Direction::values()[Direction::size() - 1]; s++) {
         if (x + s->getX() >= 0 && y + s->getY() >= 0 && x + s->getX() < maxX &&
             y + s->getY() < maxY) {
            possibleDirections.emplace_back(s);
         }
      }
   }

   auto& direction = isRestricted
                     ? *possibleDirections[Random::random(possibleDirections.size())]
                     : Direction::get(Random::random(Direction::size()));
   x += direction.getX();
   y += direction.getY();
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
