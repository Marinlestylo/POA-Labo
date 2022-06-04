//
// Created by Lazar on 02.06.2022.
//

#ifndef BUFFY_DISPLAYER_HPP
#define BUFFY_DISPLAYER_HPP

#include <list>
#include "../humanoids/Humanoid.hpp"

class Displayer {
public:
   explicit Displayer(unsigned gridSize);

   virtual ~Displayer() = default;

   virtual void displayGrid(std::list<Humanoid*>::const_iterator begin,
                            std::list<Humanoid*>::const_iterator end) = 0;

   virtual void displayPrompt(int turn) = 0;

   virtual bool getInput(Field& f) = 0;
protected:
   const unsigned gridSize;
};

#endif //BUFFY_DISPLAYER_HPP
