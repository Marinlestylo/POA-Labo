//
// Created by Lazar on 02.06.2022.
//
#include <iostream>
#include "Simulator.hpp"
#include "../displayers/ConsoleDisplayer.hpp"

using namespace std;

Simulator::Simulator(unsigned width, unsigned height, unsigned nbVampires, unsigned nbHumans,
                     Displayer* displayer) : field(width, height, nbVampires, nbHumans),
                                             displayer(displayer), ended(false) {
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


