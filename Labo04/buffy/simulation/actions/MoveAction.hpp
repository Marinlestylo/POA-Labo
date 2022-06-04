//
// Created by Lazar on 02.06.2022.
//

#ifndef BUFFY_MOVEACTION_HPP
#define BUFFY_MOVEACTION_HPP

#include "Action.hpp"

class MoveAction : public Action {
public:
   MoveAction(Humanoid* actionMaker, Humanoid* target, unsigned step);

   void execute(Field& f) override;

private:
   unsigned step;
};

#endif //BUFFY_MOVEACTION_HPP
