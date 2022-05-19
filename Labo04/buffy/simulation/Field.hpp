//
// Created by Lazar on 19.05.2022.
//

#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include "../humanoids/Humanoid.hpp"
#include <list>

class Field {
public:
	Field(int gridSize, int nbHumans, int nbVampires);

	int nextTurn();

private:
	int turn, size, nbHumans, nbVampires;
	std::list<Humanoid*> humanoids;

	void init(int gridSize, int nbHumans, int nbVampires);
};

#endif //BUFFY_FIELD_HPP
