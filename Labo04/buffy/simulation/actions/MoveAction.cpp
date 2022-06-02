//
// Created by Lazar on 02.06.2022.
//
#include "MoveAction.hpp"
#include "../utils/Utils.hpp"

MoveAction::MoveAction(Humanoid* actionMaker, unsigned step) : actionMaker(actionMaker),
                                                               step(step) {
}

void MoveAction::execute(Field& f) {
   if (step != 0) {
      while (!setNewPosition(f));
   }
}

bool MoveAction::setNewPosition(Field& f) {
   auto direction = (Direction) ((int) Utils::random() % (Direction::SIZE));
   int newX = 0, newY = 0;
   switch (direction) {
      case LEFT_UP:
         newX = int (actionMaker->getPosX() - step);
         newY = int (actionMaker->getPosY() - step);
         break;
      case UP:
         newX = int (actionMaker->getPosX());
         newY = int (actionMaker->getPosY() - step);
         break;
      case RIGHT_UP:
         newX = int (actionMaker->getPosX() + step);
         newY = int (actionMaker->getPosY() - step);
         break;
      case LEFT:
         newX = int (actionMaker->getPosX() - step);
         newY = int (actionMaker->getPosY());
         break;
      case RIGHT:
         newX = int (actionMaker->getPosX() + step);
         newY = int (actionMaker->getPosY());
         break;
      case LEFT_DOWN:
         newX = int (actionMaker->getPosX() - step);
         newY = int (actionMaker->getPosY() + step);
         break;
      case DOWN:
         newX = int (actionMaker->getPosX());
         newY = int (actionMaker->getPosY() + step);
         break;
      case RIGHT_DOWN:
         newX = int (actionMaker->getPosX() + step);
         newY = int (actionMaker->getPosY() + step);
         break;
      case SIZE:
         break;
   }
   if (newX < 0 || newY < 0 || newX >= (int) f.getSize() || newY >= (int) f.getSize()) {
      return false;
   } else {
      actionMaker->setPosX((unsigned) newX);
      actionMaker->setPosY((unsigned) newY);
      return true;
   }
}

