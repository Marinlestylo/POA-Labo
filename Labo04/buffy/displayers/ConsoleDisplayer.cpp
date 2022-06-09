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

void ConsoleDisplayer::displayGrid(std::list<Humanoid*>::const_iterator begin,
                                   std::list<Humanoid*>::const_iterator end) {
   updateGrid(begin, end);
   cout << "+" << string(width, '-') << "+" << endl;
   for (auto& row: grid) {
      cout << "|";
      for (auto& humanoid: row) {
         cout << humanoid;
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

void ConsoleDisplayer::updateGrid(std::list<Humanoid*>::const_iterator begin,
                                  std::list<Humanoid*>::const_iterator end) {
   grid.assign(height, vector<char>(width, ' '));
   for (auto iter = begin; iter != end; ++iter) {
      grid.at((*iter)->getPosition().getY()).at((*iter)->getPosition().getX()) =
         mapIdentifierToSymbol((*iter)->getIdentifier());
   }
}

char ConsoleDisplayer::mapIdentifierToSymbol(Humanoid::Identifier identifier) {
   switch (identifier) {
      case Humanoid::Identifier::HUMAN:
         return 'h';
      case Humanoid::Identifier::VAMPIRE:
         return 'V';
      case Humanoid::Identifier::BUFFY:
         return 'B';
   }
}
