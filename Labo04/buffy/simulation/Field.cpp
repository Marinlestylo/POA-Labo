//
// Created by Lazar on 19.05.2022.
//

#include <stdexcept>
#include <cmath>

#include "Field.hpp"
#include "../humanoids/Human.hpp"
#include "../humanoids/Vampire.hpp"
#include "../humanoids/Buffy.hpp"
#include "utils/Utils.hpp"

using namespace std;

Field::Field(unsigned width, unsigned height, unsigned nbVampires, unsigned nbHumans) : width
(width), height(height),nbVampires(nbVampires),nbHumans(nbHumans),turn(0) {
   if (width == 0 || height == 0 || nbHumans == 0 || nbVampires == 0) {
      throw runtime_error("Erreur: Les valeurs inserees ne peuvent pas etre nulles");
   }

   for (unsigned i = 0; i < nbHumans; i++) {
      humanoids.emplace_back(new Human(Utils::random(width), Utils::random(height)));
   }

   for (unsigned i = 0; i < nbVampires; i++) {
      humanoids.emplace_back(new Vampire(Utils::random(width), Utils::random(height)));
   }

   humanoids.emplace_back(new Buffy(Utils::random(width), Utils::random(height)));
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

Humanoid* Field::getNearestHumanoid(Position& from, Humanoid::Identifier identifier) const {
   int shortestEuclideanDistance = INT_MAX;
   Humanoid* nearestHumanoid = nullptr;
   for (auto humanoid: humanoids) {
      if (humanoid->getIdentifier() == identifier) {
         int euclideanDistance = Position::getEuclideanDistance(from, humanoid->getPosition());
         if (euclideanDistance < shortestEuclideanDistance) {
            shortestEuclideanDistance = euclideanDistance;
            nearestHumanoid = humanoid;
         }
      }
   }
   return nearestHumanoid;
}

bool Field::hasHumans() const {
   return nbHumans > 0;
}

bool Field::hasVampires() const {
   return nbVampires > 0;
}

void Field::addVampire(Vampire* vampire) {
   humanoids.emplace_back(vampire);
   nbVampires++;
}

void Field::decreasePopulation(Humanoid::Identifier targetIdentifier) {
   if (targetIdentifier == Humanoid::Identifier::HUMAN) {
      nbHumans--;
   } else if (targetIdentifier == Humanoid::Identifier::VAMPIRE) {
      nbVampires--;
   }
}
