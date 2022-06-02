//
// Created by Lazar on 02.06.2022.
//
#include <iostream>
#include "Simulator.hpp"
#include "../displayers/ConsoleDisplayer.hpp"

using namespace std;

Simulator::Simulator(unsigned gridSize, unsigned nbVampires, unsigned nbHumans,
                     const DisplayType& type) : field(gridSize, nbVampires, nbHumans) {
   displayer = chooseDisplayer(type);
}

Simulator::~Simulator() {
   delete displayer;
}

void Simulator::run() {
   if (displayer != nullptr) {
      displayer->displayGrid();
      displayer->displayPrompt(field.getTurn());
   } else {
      // TODO : Afficher les statistiques
      cout << "No displayer found" << endl;
   }
}

Displayer* Simulator::chooseDisplayer(const DisplayType& type) {
   switch (type) {
      case NO_DISPLAY:
         return nullptr;
      case CONSOLE:
      default:
         return new ConsoleDisplayer(field.getSize(), field.begin(), field.end());
   }
}


