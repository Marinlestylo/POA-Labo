//
// Created by Lazar on 19.05.2022.
//

#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include <list>

class Humanoid;

class Field {
public:
   Field(unsigned gridSize, unsigned nbVampires, unsigned nbHumans);

   ~Field();

   int nextTurn();

   void decreasePopulation(char huntedIdentifier);

   unsigned getSize() const;

   int getTurn() const;

   unsigned int getNbHumans() const;

   Humanoid* getNearestHumanoid(Humanoid* from, char identifier) const;

   std::list<Humanoid*>::const_iterator begin() const {
      return humanoids.begin();
   }

   std::list<Humanoid*>::const_iterator end() const {
      return humanoids.end();
   }

private:
   unsigned size, nbVampires, nbHumans;
private:
   int turn;
   std::list<Humanoid*> humanoids;
};

#endif //BUFFY_FIELD_HPP
