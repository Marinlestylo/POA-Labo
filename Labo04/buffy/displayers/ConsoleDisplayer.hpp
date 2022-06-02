//
// Created by Lazar on 02.06.2022.
//

#ifndef BUFFY_CONSOLEDISPLAYER_HPP
#define BUFFY_CONSOLEDISPLAYER_HPP

#include <vector>
#include "Displayer.hpp"

class ConsoleDisplayer : public Displayer {
public:
	ConsoleDisplayer(const Field* field);
	void displayAll() override;
private:
	std::vector<std::vector<char>> grid;
};

#endif //BUFFY_CONSOLEDISPLAYER_HPP
