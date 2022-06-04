//
// Created by Lazar on 02.06.2022.
//

#ifndef BUFFY_DISPLAYER_HPP
#define BUFFY_DISPLAYER_HPP

#include <list>
#include "../humanoids/Humanoid.hpp"

class Displayer {
public:
   // TODO : On ne peut pas stocker l'itérateur de début et de fin de la liste dans le constructeur
   Displayer(unsigned gridSize, std::list<Humanoid*>::const_iterator begin,
             std::list<Humanoid*>::const_iterator end);

   virtual ~Displayer() = default;

   virtual void displayGrid() = 0;

   virtual void displayPrompt(int turn) = 0;

   virtual bool getInput(Field& f) = 0;
protected:
   const unsigned gridSize;
   // TODO: iterator const ??
   std::list<Humanoid*>::const_iterator begin;
   std::list<Humanoid*>::const_iterator end;
};

#endif //BUFFY_DISPLAYER_HPP
