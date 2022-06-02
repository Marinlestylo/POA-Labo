//
// Created by Lazar on 02.06.2022.
//

#ifndef BUFFY_DISPLAYER_HPP
#define BUFFY_DISPLAYER_HPP

#include <list>
#include "../humanoids/Humanoid.hpp"

class Displayer {
public:
	Displayer(unsigned gridSize, std::list<Humanoid*>::const_iterator begin,
				 std::list<Humanoid*>::const_iterator end);
	virtual ~Displayer() = default;
	virtual void displayAll() = 0;
protected:
	const unsigned gridSize;
	// TODO: iterator const ??
	std::list<Humanoid*>::const_iterator begin;
	std::list<Humanoid*>::const_iterator end;
};

#endif //BUFFY_DISPLAYER_HPP
