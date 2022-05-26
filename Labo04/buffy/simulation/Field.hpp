//
// Created by Lazar on 19.05.2022.
//

#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include "../humanoids/Humanoid.hpp"
#include <list>

class Humanoid;

class Field {
public:
   Field(unsigned gridSize, unsigned nbHumans, unsigned nbVampires);

   ~Field();

   int nextTurn();

private:
   unsigned size;
   int turn;
   std::list<Humanoid*> humanoids;
};

#endif //BUFFY_FIELD_HPP
