//
// Created by Lazar on 02.06.2022.
//
#include <iostream>
#include "ConsoleDisplayer.hpp"

using namespace std;

ConsoleDisplayer::ConsoleDisplayer(unsigned int gridSize, list<Humanoid*>::const_iterator begin,
                                   list<Humanoid*>::const_iterator end)
   : Displayer(gridSize, begin, end), grid(gridSize, vector<char>(gridSize, ' ')) {
}

void ConsoleDisplayer::displayGrid() {
   updateGrid();

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

void ConsoleDisplayer::displayPrompt(int turn) {
   cout << "[" << turn << "] q>uit s>tatistics n>ext: ";
}

void ConsoleDisplayer::updateGrid() {
   grid.assign(gridSize, vector<char>(gridSize, ' '));
   for (auto iter = begin; iter != end; ++iter) {
      grid.at((*iter)->getPosX()).at((*iter)->getPosY()) = (*iter)->getIdentifier();
   }
}

bool ConsoleDisplayer::getInput(Field& f) {
   string input;
   getline(cin, input);
   if (input == "q") {
      return true;
   } else if (input == "s") {
      cout << "Statistics" << endl; // TODO lancer simulation
   } else if (input == "n" || input.empty()) {
      f.nextTurn();
   } else {
      cout << "Invalid input" << endl;
   }
   return false;
}
