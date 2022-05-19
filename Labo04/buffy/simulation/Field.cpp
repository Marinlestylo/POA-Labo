//
// Created by Lazar on 19.05.2022.
//

#include <stdexcept>
#include "Field.hpp"

using namespace std;

Field::Field(int gridSize, int nbHumans, int nbVampires) {
	init(gridSize, nbHumans, nbVampires);
}

void Field::init(int gridSize, int nbHumans, int nbVampires) {
	if (gridSize <= 0 || nbHumans <= 0 || nbVampires <= 0) {
		throw runtime_error("Erreur: Les valeurs inserees ne peuvent pas etre nulles ou negatives");
	}
	size = gridSize;
	this->nbHumans = nbHumans;
	this->nbVampires = nbVampires;
	turn = 0;
	// TODO: add n humans and m vampires in humanoids
}

int Field::nextTurn() {
	// Déterminer les prochaines actions
	for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
		(*it)->setAction(*this);
	// Executer les actions
	for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
		(*it)->executeAction(*this);
	// Enlever les humanoides tués
	for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end();)
		if (!(*it)->isAlive()) {
			it = humanoids.erase(it); // suppression de l’élément dans la liste
			delete *it; // destruction de l’humanoide référencé
		} else
			++it;
	return turn++;
}