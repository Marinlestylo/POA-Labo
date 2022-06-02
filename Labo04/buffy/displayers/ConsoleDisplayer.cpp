//
// Created by Lazar on 02.06.2022.
//
#include <iostream>
#include "ConsoleDisplayer.hpp"
#include "../humanoids/Humanoid.hpp"

using namespace std;

ConsoleDisplayer::ConsoleDisplayer(unsigned int gridSize, const Field* field) :
	Displayer(gridSize, field), grid(gridSize, vector<char>(gridSize, ' ')){

	for (auto iter : *field) {
		grid.at(iter->getPosX()).at(iter->getPosY()) = iter->getIdentifier();
	}
}

void ConsoleDisplayer::displayAll() {
	cout << "╔" << string(getGridSize(), '-') << "╗" << endl;
	for (auto iter : grid) {
		cout << "|";
		for (auto iter2 : iter) {
			cout << iter2;
		}
		cout << "|" << endl;
	}
	cout << "╚" << string(getGridSize(), '-') << "╝" << endl;
}
