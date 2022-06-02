//
// Created by Lazar on 02.06.2022.
//

#ifndef BUFFY_CONSOLEDISPLAYER_HPP
#define BUFFY_CONSOLEDISPLAYER_HPP

#include <vector>
#include "Displayer.hpp"

class ConsoleDisplayer : public Displayer {
public:
	ConsoleDisplayer(unsigned gridSize, std::list<Humanoid*>::const_iterator begin,
						  std::list<Humanoid*>::const_iterator end);
   void displayGrid() override;
   void displayPrompt(int turn) override;
private:
	std::vector<std::vector<char>> grid;
};

#endif //BUFFY_CONSOLEDISPLAYER_HPP
