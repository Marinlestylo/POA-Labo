//
// Created by Lazar on 04.06.2022.
//

#ifndef BUFFY_DIRECTION_HPP
#define BUFFY_DIRECTION_HPP

class Direction {
public:

   static const Direction& get(unsigned i);

   static unsigned size();

   int getX() const;

   int getY() const;

   Direction(const Direction& other) = delete;

   Direction& operator=(const Direction& other) = delete;

private:
   Direction(int x, int y);

   static const Direction LEFT_UP, UP, RIGHT_UP, LEFT, RIGHT, LEFT_DOWN, DOWN, RIGHT_DOWN;
   static unsigned COUNT;
   static const Direction* DIRECTIONS[];
   int x, y;
};


#endif //BUFFY_DIRECTION_HPP
