//
// Created by Lazar on 02.06.2022.
//
#include <iostream>
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

void ConsoleDisplayer::updateGrid(std::list<Humanoid*>::const_iterator begin,
                                  std::list<Humanoid*>::const_iterator end) {
   grid.assign(height, vector<char>(width, ' '));
   for (auto iter = begin; iter != end; ++iter) {
      grid.at((*iter)->getPosY()).at((*iter)->getPosX()) = (*iter)->getIdentifier();
   }
}

void ConsoleDisplayer::displayPrompt(int turn) {
   cout << "[" << turn << "] q>uit s>tatistics n>ext:";
}

bool ConsoleDisplayer::getInput(Field& f) {
   string input;
   getline(cin, input);
   if (input == "q") {
      return true;
   } else if (input == "s") {
      // TODO lancer une simulation avec un nouveau field dédié
      cout << "Statistics" << endl;
   } else if (input == "n" || input.empty()) {
      f.nextTurn();
   } else {
      cout << "Invalid input" << endl;
   }
   return false;
}
