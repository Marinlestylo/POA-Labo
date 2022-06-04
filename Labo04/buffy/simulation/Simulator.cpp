//
// Created by Lazar on 02.06.2022.
//
#include <iostream>
#include "Simulator.hpp"
#include "../displayers/ConsoleDisplayer.hpp"

using namespace std;

Simulator::Simulator(unsigned gridSize, unsigned nbVampires, unsigned nbHumans,
                     const DisplayType& type) : field(gridSize, nbVampires, nbHumans),
                                                ended(false) {
   displayer = chooseDisplayer(type);
}

Simulator::~Simulator() {
   delete displayer;
}

void Simulator::run() {
   while (!ended) {
      if (displayer != nullptr) {
         displayer->displayGrid(field.begin(), field.end());
         displayer->displayPrompt(field.getTurn());
         ended = displayer->getInput(field);
      } else {
         // TODO : Afficher les statistiques
         cout << "No displayer found" << endl;
      }
   }

}

// TODO : Ca dégage
Displayer* Simulator::chooseDisplayer(const DisplayType& type) {
   switch (type) {
      case NO_DISPLAY:
         return nullptr;
      case CONSOLE:
      default:
         return new ConsoleDisplayer(field.getSize());
   }
}


