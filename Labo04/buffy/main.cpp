#include <iostream>
#include "simulation/Field.hpp"
#include "displayers/ConsoleDisplayer.hpp"

int main(int argc, char* argv[]) {
   int val[3];
   if (argc != 4) {
      throw std::runtime_error("Usage : buffy <taille de la grille> <nombre d'humains> <nombre "
                               "de vampires>");
   }
   for (unsigned i = 1; i < 4; ++i) {
      val[i - 1] = std::stoi(argv[i]);
      if (val[i - 1] <= 0) {
         throw std::invalid_argument("La taille de la grille, le nombre d'humain et le nombre de"
                                     " vampires doivent etre plus grand que 0");
      }
   }

   Field field = Field((unsigned)val[0], (unsigned)val[1], (unsigned)val[2]);
	ConsoleDisplayer displayer(val[0], &field);

	displayer.displayAll();

   return 0;
}
