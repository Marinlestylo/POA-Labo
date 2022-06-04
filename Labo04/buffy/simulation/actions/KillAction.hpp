//
// Created by Lazar on 03.06.2022.
//

#ifndef BUFFY_KILLACTION_HPP
#define BUFFY_KILLACTION_HPP

#include "Action.hpp"

class KillAction : public Action {
public:
   KillAction(Humanoid* actionMaker, Humanoid* target);

   void execute(Field& f) override;

private:
   Humanoid* target;
};


#endif //BUFFY_KILLACTION_HPP
