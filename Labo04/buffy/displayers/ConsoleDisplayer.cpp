/**
 * Classe gérant l'affichage d'une simulation dans une console
 *
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include <iostream>
#include "../simulation/Field.hpp"
#include "../simulation/Simulator.hpp"
#include "ConsoleDisplayer.hpp"
#include "../humanoids/Human.hpp"
#include "utils/termcolor.hpp"

using namespace std;

ConsoleDisplayer::ConsoleDisplayer(unsigned width, unsigned height)
   : Displayer(width, height), grid(height, vector<char>(width, ' ')) {
}

void ConsoleDisplayer::displayGrid(list<Humanoid*>::const_iterator begin,
                                   list<Humanoid*>::const_iterator end) {
   updateGrid(begin, end);
   cout << "+" << string(width, '-') << "+" << endl;
   for (auto& row: grid) {
      cout << "|";
      for (auto& humanoid: row) {
         printHumanoid(humanoid);
         cout << termcolor::reset;
      }
      cout << "|" << endl;
   }
   cout << "+" << string(width, '-') << "+" << endl;
}

void ConsoleDisplayer::displayPrompt(int turn) {
   cout << "[" << turn << "] q)uit s)tatistics n)ext:";
}

bool ConsoleDisplayer::getInput(Field& f, Simulator& s) {
   string input;
   getline(cin, input);
   if (input == "q") {
      return true;
   } else if (input == "s") {
      cout << "Simulating..." << endl;
      double saves = s.simulate();
      cout << "For " << s.getNbSimulation() << " simulations : succes rate of " << saves * 100
           << "%" << endl;
   } else if (input == "n" || input.empty()) {
      f.nextTurn();
   } else {
      cout << "Invalid input" << endl;
   }
   return false;
}

void ConsoleDisplayer::updateGrid(list<Humanoid*>::const_iterator begin,
                                  list<Humanoid*>::const_iterator end) {
   grid.assign(height, vector<char>(width, ' '));
   for (auto iter = begin; iter != end; ++iter) {
      grid.at((*iter)->getPosition().getY()).at((*iter)->getPosition().getX()) = mapToSymbol(iter);
   }
}

char ConsoleDisplayer::mapToSymbol(list<Humanoid*>::const_iterator iter) {
   if (dynamic_cast<Human*>(*iter) != nullptr) {
      return 'h';
   } else if (dynamic_cast<Vampire*>(*iter) != nullptr) {
      return 'V';
   } else {
      return 'B';
   }
}

void ConsoleDisplayer::printHumanoid(char humanoid) {
   switch (humanoid) {
      case 'h':
         cout << termcolor::bright_cyan << humanoid;
         break;
      case 'V':
         cout << termcolor::red << humanoid;
         break;
      case 'B':
         cout << termcolor::yellow << humanoid;
         break;
      default:
         cout << termcolor::white << humanoid;
   }
}
