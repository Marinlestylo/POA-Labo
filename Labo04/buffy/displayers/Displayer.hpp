//
// Created by Lazar on 02.06.2022.
//

#ifndef BUFFY_DISPLAYER_HPP
#define BUFFY_DISPLAYER_HPP

#include <list>
#include "../humanoids/Humanoid.hpp"

class Simulator;

class Displayer {
public:
   Displayer(unsigned width, unsigned height);

   virtual ~Displayer() = default;

   virtual void displayGrid(std::list<Humanoid*>::const_iterator begin,
                            std::list<Humanoid*>::const_iterator end) = 0;

   virtual void displayPrompt(int turn) = 0;

   virtual bool getInput(Field& f, Simulator& s) = 0;
protected:
   const unsigned width, height;
};

#endif //BUFFY_DISPLAYER_HPP
