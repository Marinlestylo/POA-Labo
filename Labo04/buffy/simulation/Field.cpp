//
// Created by Lazar on 19.05.2022.
//

#include <stdexcept>
#include "Field.hpp"
#include "../humanoids/Human.hpp"
#include "../humanoids/Vampire.hpp"
#include "../humanoids/Buffy.hpp"
#include "utils/Utils.hpp"

using namespace std;

Field::Field(unsigned gridSize, unsigned nbVampires, unsigned nbHumans) {
   if (gridSize == 0 || nbHumans == 0 || nbVampires == 0) {
      throw runtime_error("Erreur: Les valeurs inserees ne peuvent pas etre nulles");
   }
   size = gridSize;
   turn = 0;

   for (unsigned i = 0; i < nbHumans; i++) {
      humanoids.emplace_back(new Human(Utils::random(gridSize), Utils::random(gridSize)));
   }

   for (unsigned i = 0; i < nbVampires; i++) {
      humanoids.emplace_back(new Vampire(Utils::random(gridSize), Utils::random(gridSize)));
   }

   humanoids.emplace_back(new Buffy(Utils::random(gridSize), Utils::random(gridSize)));
}


Field::~Field() {
   for (auto humanoid : humanoids) {
      delete humanoid;
   }
}

int Field::nextTurn() {
   // Déterminer les prochaines actions
   for (auto& humanoid : humanoids)
      humanoid->setAction(*this);
   // Executer les actions
   for (auto & humanoid : humanoids)
      humanoid->executeAction(*this);
   // Enlever les humanoides tués
   for (auto it = humanoids.begin(); it != humanoids.end();)
      if (!(*it)->isAlive()) {
         it = humanoids.erase(it); // suppression de l’élément dans la liste
         delete *it; // destruction de l’humanoide référencé
      } else
         ++it;
   return turn++;
}

unsigned Field::getSize() const {
	return size;
}

int Field::getTurn() const {
   return turn;
}