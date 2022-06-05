//
// Created by Lazar on 02.06.2022.
//
#include <iostream>
#include "Simulator.hpp"
#include "../displayers/ConsoleDisplayer.hpp"

using namespace std;

Simulator::Simulator(unsigned nbSimulation, unsigned width, unsigned height, unsigned
nbVampires, unsigned nbHumans,
                     Displayer* displayer) : nbSimulation(nbSimulation),
                                             width(width), height(height), nbVampires(nbVampires),
                                             nbHumans(nbHumans),
                                             field(width, height, nbVampires, nbHumans),
                                             simulationField(nullptr),
                                             displayer(displayer), ended(false) {
}

Simulator::~Simulator() {
   delete displayer;
   delete simulationField;
}

void Simulator::run() {
   while (!ended) {
      if (displayer != nullptr) {
         displayer->displayGrid(field.begin(), field.end());
         displayer->displayPrompt(field.getTurn());
         ended = displayer->getInput(field, *this);
      } else {
         // TODO : Afficher les statistiques
         cout << "No displayer found" << endl;
      }
   }
}

double Simulator::simulate() {
   int nbSaves = 0;
   for (unsigned i = 0; i < nbSimulation; ++i) {
      if (simulationField != nullptr) {
         delete simulationField;
         simulationField = nullptr;
      }
      simulationField = new Field(width, height, nbVampires, nbHumans);
      while (simulationField->hasVampires()) {
         simulationField->nextTurn();
      }
      if (simulationField->hasHumans()) {
         ++nbSaves;
      }
   }
   return nbSaves / (double)nbSimulation;
}

unsigned Simulator::getNbSimulation() const {
   return nbSimulation;
}


