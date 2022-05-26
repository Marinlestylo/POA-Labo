//
// Created by Jonathan on 19.05.2022.
//

#ifndef BUFFY_DISPLAYER_HPP
#define BUFFY_DISPLAYER_HPP


#include "../humanoids/Humanoid.hpp"

class Displayer {
public:
    Displayer(unsigned gridSize, std::list<Humanoid*>* humanoids);
    void displayAll();
private:
    unsigned gridSize;
    std::list<Humanoid*>* humanoids;
};


#endif //BUFFY_DISPLAYER_HPP
