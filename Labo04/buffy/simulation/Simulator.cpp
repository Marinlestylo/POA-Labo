//
// Created by Lazar on 02.06.2022.
//
#include "Simulator.hpp"
#include "../displayers/ConsoleDisplayer.hpp"

using namespace std;

Simulator::Simulator(unsigned int gridSize, unsigned int nbHumans, unsigned int nbVampires,
							const DisplayType& type) : field(gridSize, nbHumans, nbVampires) {
	displayer = chooseDisplayer(type);
}

Simulator::~Simulator() {
	delete displayer;
}

void Simulator::run() {
	displayer->displayAll();
}

Displayer* Simulator::chooseDisplayer(const DisplayType& type) {
	switch (type) {
		case CONSOLE:
			return new ConsoleDisplayer(field.getSize(), field.begin(), field.end());
		case NO_DISPLAY:
		default:
			return nullptr;
	}
}


