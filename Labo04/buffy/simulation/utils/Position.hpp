//
// Created by Lazar on 04.06.2022.
//

#ifndef BUFFY_POSITION_HPP
#define BUFFY_POSITION_HPP

class Position {
public:
   static int getEuclideanDistance(Position& from, Position& to);

   Position(int x, int y);

   int getX() const;

   void setX(int x);

   int getY() const;

   void setY(int y);

   void setRandomPosition(int maxX, int maxY);

   void setDirectedPosition(Position& target, int step, int maxX, int maxY);

private :
   int x, y;
};


#endif //BUFFY_POSITION_HPP
