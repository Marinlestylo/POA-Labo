//
// Created by Lazar on 19.05.2022.
//

#ifndef BUFFY_ACTION_HPP
#define BUFFY_ACTION_HPP

class Field;

class Humanoid;

class Action {
public:
   explicit Action(Humanoid* actionMaker);

   virtual void execute(Field& f) = 0;

   virtual ~Action() = default;

protected:
   // TODO: Ajouter un humanoid target
   Humanoid* actionMaker;
};


#endif //BUFFY_ACTION_HPP
