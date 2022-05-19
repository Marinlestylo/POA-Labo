//
// Created by Lazar on 19.05.2022.
//

#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "../Field.hpp"
#include "../Action.hpp"

class Humanoid {

public:
	void setAction(Field field);

	void executeAction(Field field);

	bool isAlive();

private:
	Action& action;
};

#endif //BUFFY_HUMANOID_HPP
