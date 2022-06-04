#include <iostream>
#include "simulation/Simulator.hpp"
#include "displayers/ConsoleDisplayer.hpp"

#define NB_ARGS 4

int main(int argc, char* argv[]) {
   unsigned values[NB_ARGS];

   if (argc != NB_ARGS + 1) {
      throw std::invalid_argument("Usage : buffy <largeur grille> <hauteur grille> <nb vampires>"
                                  " <nb humains>");
   }
   for (unsigned i = 1; i < NB_ARGS + 1; ++i) {
      if (std::stoi(argv[i]) <= 0) {
         throw std::invalid_argument("La taille de la grille, le nombre d'humain et le nombre de"
                                     " vampires doivent etre plus grand que 0");
      }
      values[i - 1] = (unsigned)std::stoi(argv[i]);
   }

   unsigned width = values[0], height = values[1], nbVampires = values[2], nbHumans = values[3];
   auto displayer = new ConsoleDisplayer(width, height);

   Simulator simulator(width, height, nbVampires, nbHumans, displayer);
   simulator.run();

   return EXIT_SUCCESS;
}
