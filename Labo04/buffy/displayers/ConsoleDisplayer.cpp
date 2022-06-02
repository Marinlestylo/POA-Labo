//
// Created by Lazar on 02.06.2022.
//
#include <iostream>
#include "ConsoleDisplayer.hpp"
#include "../humanoids/Humanoid.hpp"

using namespace std;

ConsoleDisplayer::ConsoleDisplayer(const Field* field) :
	Displayer(field), grid(field->getSize(), vector<char>(field->getSize(), ' ')){
	for (auto iter : *field) {
		grid.at(iter->getPosX()).at(iter->getPosY()) = iter->getIdentifier();
	}
}

void ConsoleDisplayer::displayAll() {
	cout << "╔" << string(field->getSize(), '-') << "╗" << endl;
	for (auto &row : grid) {
		cout << "|";
		for (auto &humanoid : row) {
			cout << humanoid;
		}
		cout << "|" << endl;
	}
	cout << "╚" << string(field->getSize(), '-') << "╝" << endl;
}
