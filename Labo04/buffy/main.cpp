/**
 * Classe représentant le point d'entrée du programme
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include <iostream>
#include "simulation/Simulator.hpp"
#include "displayers/ConsoleDisplayer.hpp"

#define NB_ARGS 4
#define NB_SIMULATION 10000

int main(int argc, char* argv[]) {
   unsigned values[NB_ARGS];

   if (argc != NB_ARGS + 1) {
      throw std::invalid_argument("Usage : buffy <largeur grille> <hauteur grille> <nb vampires>"
                                  " <nb humains>");
   }
   try{
       for (unsigned i = 1; i < NB_ARGS + 1; ++i) {
           if (std::stoi(argv[i]) <= 0) {
               throw std::exception();
           }
           values[i - 1] = (unsigned)std::stoi(argv[i]);
       }
   }catch (const std::exception&){ // Permet de catch les exceptions de std::stoi
		// et si la valeur est < 1
       throw std::invalid_argument("Les arguments doivent etre des nombres entiers positifs !");
   }


   unsigned width = values[0], height = values[1], nbVampires = values[2], nbHumans = values[3];
   ConsoleDisplayer displayer(width, height);

   Simulator simulator(NB_SIMULATION, width, height, nbVampires, nbHumans, displayer);
   simulator.run();

   return EXIT_SUCCESS;
}
