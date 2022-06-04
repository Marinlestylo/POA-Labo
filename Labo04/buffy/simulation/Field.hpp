//
// Created by Lazar on 19.05.2022.
//

#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include <list>

class Humanoid;

class Vampire;

class Field {
public:
   Field(unsigned width, unsigned height, unsigned nbVampires, unsigned nbHumans);

   ~Field();

   int nextTurn();

   unsigned getWidth() const;

   unsigned getHeight() const;

   int getTurn() const;

   unsigned getNbHumans() const;

   unsigned getNbVampires() const;

   Humanoid* getNearestHumanoid(Humanoid* from, char identifier) const;

   std::list<Humanoid*>::const_iterator begin() const {
      return humanoids.begin();
   }

   std::list<Humanoid*>::const_iterator end() const {
      return humanoids.end();
   }

   void decreasePopulation(char huntedIdentifier);

   void addVampire(Vampire* vampire);

private:
   unsigned width, height, nbVampires, nbHumans;
private:
   int turn;
   std::list<Humanoid*> humanoids;
};

#endif //BUFFY_FIELD_HPP
