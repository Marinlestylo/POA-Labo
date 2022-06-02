//
// Created by Lazar on 02.06.2022.
//
#include <iostream>
#include "ConsoleDisplayer.hpp"

using namespace std;

ConsoleDisplayer::ConsoleDisplayer(unsigned int gridSize, list<Humanoid*>::const_iterator begin,
											  list<Humanoid*>::const_iterator end)
	: Displayer(gridSize, begin, end), grid(gridSize, vector<char>(gridSize, ' ')) {
	for (auto iter = begin; iter != end; ++iter) {
		grid.at((*iter)->getPosX()).at((*iter)->getPosY()) = (*iter)->getIdentifier();
	}
}

void ConsoleDisplayer::displayAll() {
	cout << "╔" << string(gridSize, '-') << "╗" << endl;
	for (auto& row: grid) {
		cout << "|";
		for (auto& humanoid: row) {
			cout << humanoid;
		}
		cout << "|" << endl;
	}
	cout << "╚" << string(gridSize, '-') << "╝" << endl;
}
