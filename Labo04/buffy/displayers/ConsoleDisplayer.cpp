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

using namespace std;

ConsoleDisplayer::ConsoleDisplayer(unsigned width, unsigned height)
   : Displayer(width, height), grid(height, vector<char>(width, ' ')) {
}

void ConsoleDisplayer::displayGrid(list<Humanoid*>::const_iterator begin,
                                   list<Humanoid*>::const_iterator end) {
   updateGrid(begin, end);
   cout << "+" << string(getWidth(), '-') << "+" << endl;
   for (auto& row: grid) {
      cout << "|";
      for (auto& humanoid: row) {
         cout << humanoid;
      }
      cout << "|" << endl;
   }
   cout << "+" << string(getWidth(), '-') << "+" << endl;
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
   grid.assign(getHeight(), vector<char>(getWidth(), ' '));
   for (auto iter = begin; iter != end; ++iter) {
      grid.at((size_t)(*iter)->getPosition().getY())
         .at((size_t)(*iter)->getPosition().getX()) = (*iter)->getSymbol();
   }
}
