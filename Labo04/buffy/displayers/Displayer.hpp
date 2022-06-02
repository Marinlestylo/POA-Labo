//
// Created by Lazar on 02.06.2022.
//

#ifndef BUFFY_DISPLAYER_HPP
#define BUFFY_DISPLAYER_HPP

#include "../simulation/Field.hpp"

class Displayer {
public:
	Displayer(const Field* field);
	~Displayer() = default;
	virtual void displayAll() = 0;
protected:
	const Field* field;
};

#endif //BUFFY_DISPLAYER_HPP
