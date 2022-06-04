//
// Created by Lazar on 02.06.2022.
//
#include <iostream>
#include "ConsoleDisplayer.hpp"

using namespace std;

ConsoleDisplayer::ConsoleDisplayer(unsigned int gridSize)
: Displayer(gridSize), grid(gridSize, vector<char>(gridSize, ' ')) {
}

void ConsoleDisplayer::displayGrid(std::list<Humanoid*>::const_iterator begin,
                                   std::list<Humanoid*>::const_iterator end) {
   updateGrid(begin, end);

   cout << "+" << string(gridSize, '-') << "+" << endl;
   for (auto& row: grid) {
      cout << "|";
      for (auto& humanoid: row) {
         cout << humanoid;
      }
      cout << "|" << endl;
   }
   cout << "+" << string(gridSize, '-') << "+" << endl;
}

void ConsoleDisplayer::updateGrid(std::list<Humanoid*>::const_iterator begin,
                                  std::list<Humanoid*>::const_iterator end) {
   grid.assign(gridSize, vector<char>(gridSize, ' '));
   for (auto iter = begin; iter != end; ++iter) {
      grid.at((*iter)->getPosX()).at((*iter)->getPosY()) = (*iter)->getIdentifier();
   }
}

void ConsoleDisplayer::displayPrompt(int turn) {
   cout << "[" << turn << "] q>uit s>tatistics n>ext: ";
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
