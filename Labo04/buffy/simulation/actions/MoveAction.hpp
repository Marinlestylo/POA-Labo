//
// Created by Lazar on 02.06.2022.
//

#ifndef BUFFY_MOVEACTION_HPP
#define BUFFY_MOVEACTION_HPP

#include "Action.hpp"
#include "../../humanoids/Humanoid.hpp"

class MoveAction : public Action {
public:
   MoveAction(Humanoid* actionMaker, unsigned step);
   void execute(Field& f) override;

private:
   enum Direction {
      LEFT_UP,
      UP,
      RIGHT_UP,
      LEFT,
      RIGHT,
      LEFT_DOWN,
      DOWN,
      RIGHT_DOWN,
      SIZE
   };

   bool setNewPosition(Field& f);

   Humanoid* actionMaker;
   unsigned step;
};

#endif //BUFFY_MOVEACTION_HPP
