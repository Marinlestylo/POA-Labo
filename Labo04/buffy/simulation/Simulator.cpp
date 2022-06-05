/**
 * Classe contrôlant la simulation du jeu
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Simulator.hpp"

using namespace std;

Simulator::Simulator(unsigned nbSimulation, unsigned width, unsigned height, unsigned
nbVampires, unsigned nbHumans, Displayer& displayer) : nbSimulation(nbSimulation),
                                                       width(width), height(height),
                                                       nbVampires(nbVampires),
                                                       nbHumans(nbHumans),
                                                       field(width, height, nbVampires, nbHumans),
                                                       displayer(displayer), ended(false) {
}

void Simulator::run() {
   while (!ended) {
      displayer.displayGrid(field.begin(), field.end());
      displayer.displayPrompt(field.getTurn());
      ended = displayer.getInput(field, *this);
   }
}

double Simulator::simulate() const {
   int nbSaves = 0;
   for (unsigned i = 0; i < nbSimulation; ++i) {
      Field simulationField(width, height, nbVampires, nbHumans);
      while (simulationField.hasVampires()) {
         simulationField.nextTurn();
      }
      if (simulationField.hasHumans()) {
         ++nbSaves;
      }
   }
   return nbSaves / (double)nbSimulation;
}

unsigned Simulator::getNbSimulation() const {
   return nbSimulation;
}


