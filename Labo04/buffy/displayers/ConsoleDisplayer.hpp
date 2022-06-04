//
// Created by Lazar on 02.06.2022.
//

#ifndef BUFFY_CONSOLEDISPLAYER_HPP
#define BUFFY_CONSOLEDISPLAYER_HPP

#include <vector>
#include "Displayer.hpp"

class ConsoleDisplayer : public Displayer {
public:
   ConsoleDisplayer(unsigned width, unsigned height);

   void displayGrid(std::list<Humanoid*>::const_iterator begin,
                    std::list<Humanoid*>::const_iterator end) override;

   void displayPrompt(int turn) override;

   bool getInput(Field& f) override;

private:
   void updateGrid(std::list<Humanoid*>::const_iterator begin,
                   std::list<Humanoid*>::const_iterator end);

   std::vector<std::vector<char>> grid;
};

#endif //BUFFY_CONSOLEDISPLAYER_HPP
