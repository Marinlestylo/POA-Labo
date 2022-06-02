//
// Created by Lazar on 19.05.2022.
//

#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include <list>

class Humanoid;

class Field {
public:
   Field(unsigned gridSize, unsigned nbHumans, unsigned nbVampires);

   ~Field();

   int nextTurn();

	unsigned getSize() const;

	std::list<Humanoid*>::const_iterator begin() const {
		return humanoids.begin();
	}

	std::list<Humanoid*>::const_iterator end() const {
		return humanoids.end();
	}

private:
   unsigned size;
   int turn;
   std::list<Humanoid*> humanoids;
};

#endif //BUFFY_FIELD_HPP
