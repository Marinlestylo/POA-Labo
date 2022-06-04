//
// Created by Lazar on 03.06.2022.
//

#ifndef BUFFY_TRANSFORMACTION_HPP
#define BUFFY_TRANSFORMACTION_HPP


#include "Action.hpp"

class TransformAction : public Action {
public:
    TransformAction(Humanoid* actionMaker, Humanoid* target, unsigned int step);
    void execute(Field& f) override;
};


#endif //BUFFY_TRANSFORMACTION_HPP
