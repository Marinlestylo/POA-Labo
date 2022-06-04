//
// Created by Lazar on 02.06.2022.
//
#include "MoveAction.hpp"
#include "../Field.hpp"
#include "../utils/Utils.hpp"

MoveAction::MoveAction(Humanoid* actionMaker, unsigned int step) : Action(actionMaker), step(step) {
}

void MoveAction::execute(Field& f) {
   if (step != 0) {
      while (!setNewPosition(f));
   }
}

bool MoveAction::setNewPosition(Field& f) {

   // TODO : Gérer les déplacements vers les cibles

   auto direction = (Direction) ((int) Utils::random(Direction::SIZE));
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
   if (newX < 0 || newY < 0 || newX >= (int) f.getWidth() || newY >= (int) f.getHeight()) {
      return false;
   } else {
      actionMaker->setPosX((unsigned) newX);
      actionMaker->setPosY((unsigned) newY);
      return true;
   }
}

