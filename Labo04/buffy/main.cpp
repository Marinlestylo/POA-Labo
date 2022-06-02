#include <iostream>
#include "simulation/Simulator.hpp"

#define MIN_ARGS 4
#define MAX_ARGS 5

int main(int argc, char* argv[]) {
   unsigned values[MIN_ARGS - 1];

   if (argc < MIN_ARGS || argc > MAX_ARGS) {
      throw std::invalid_argument("Usage : buffy <taille de la grille> <nombre d'humains> <nombre "
                                  "de vampires> [<mode d'affichage>]");
   }
   for (unsigned i = 1; i < MIN_ARGS; ++i) {
      if (std::stoi(argv[i]) <= 0) {
         throw std::invalid_argument("La taille de la grille, le nombre d'humain et le nombre de"
                                     " vampires doivent etre plus grand que 0");
      }
      values[i - 1] = (unsigned)std::stoi(argv[i]);
   }
   DisplayType displayType = DisplayType::CONSOLE;

   if (argc == MAX_ARGS) {
      displayType = Utils::getDisplayType(argv[MIN_ARGS]);
   }

   unsigned gridSize = values[0], nbVampires = values[1], nbHumans = values[2];
   Simulator simulator(gridSize, nbVampires, nbHumans, displayType);

   simulator.run();

   return EXIT_SUCCESS;
}
