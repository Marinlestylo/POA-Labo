/**
 * Classe représentant le terrain de jeu contenant une liste d'humanoïdes.
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include <stdexcept>
#include <climits>

#include "Field.hpp"
#include "../humanoids/Human.hpp"
#include "../humanoids/Buffy.hpp"
#include "utils/Random.hpp"

using namespace std;

Field::Field(unsigned width, unsigned height, unsigned nbVampires, unsigned nbHumans)
   : width(width), height(height), nbVampires(nbVampires), nbHumans(nbHumans), turn(0) {
   if (width == 0 || height == 0 || nbHumans == 0 || nbVampires == 0) {
      throw runtime_error("Erreur: Les valeurs inserees ne peuvent pas etre nulles");
   }

   for (unsigned i = 0; i < nbHumans; i++) {
      humanoids.emplace_back(new Human(Random::random(width), Random::random(height)));
   }

   for (unsigned i = 0; i < nbVampires; i++) {
      humanoids.emplace_back(new Vampire(Random::random(width), Random::random(height)));
   }

   humanoids.emplace_back(new Buffy(Random::random(width), Random::random(height)));
}


Field::~Field() {
   for (auto& humanoid: humanoids) {
      delete humanoid;
   }
}

int Field::nextTurn() {
   // Déterminer les prochaines actions
   for (auto& humanoid: humanoids)
      humanoid->setAction(*this);
   // Executer les actions
   for (auto& humanoid: humanoids)
      humanoid->executeAction(*this);
   // Enlever les humanoides tués
   for (auto it = humanoids.begin(); it != humanoids.end();)
      if (!(*it)->isAlive()) {
         delete *it; // destruction de l’humanoide référencé
         it = humanoids.erase(it); // suppression de l’élément dans la liste
      } else
         ++it;
   return turn++;
}

unsigned Field::getWidth() const {
   return width;
}

unsigned Field::getHeight() const {
   return height;
}

int Field::getTurn() const {
   return turn;
}

bool Field::hasHumans() const {
   return nbHumans > 0;
}

bool Field::hasVampires() const {
   return nbVampires > 0;
}

std::list<Humanoid*>::const_iterator Field::begin() const {
   return humanoids.begin();
}

std::list<Humanoid*>::const_iterator Field::end() const {
   return humanoids.end();
}

void Field::decreasePopulation(Humanoid* target) {
   if (dynamic_cast<Human*>(target) != nullptr) {
      nbHumans--;
   } else if (dynamic_cast<Vampire*>(target) != nullptr) {
      nbVampires--;
   }
}

void Field::addVampire(Vampire* vampire) {
   humanoids.emplace_back(vampire);
   nbVampires++;
}
