//
// Created by Lazar on 02.06.2022.
//

#ifndef BUFFY_SIMULATOR_HPP
#define BUFFY_SIMULATOR_HPP

#include <string>
#include "../displayers/Displayer.hpp"
#include "Field.hpp"
#include "utils/Utils.hpp"

class Simulator {
public:
	 Simulator(unsigned gridSize, unsigned nbHumans, unsigned nbVampires, const DisplayType& type);
	 ~Simulator();

	 void run();

private:
	Displayer* chooseDisplayer(const DisplayType& type);

	const Field field;
	Displayer* displayer;
};

#endif //BUFFY_SIMULATOR_HPP
