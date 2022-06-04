//
// Created by Lazar on 19.05.2022.
//

#ifndef BUFFY_ACTION_HPP
#define BUFFY_ACTION_HPP

class Field;

class Humanoid;

class Action {
public:
   Action(Humanoid* actionMaker, Humanoid* target);

   virtual void execute(Field& f) = 0;

   virtual ~Action() = default;

protected:
   Humanoid* actionMaker;
   Humanoid* target;
};


#endif //BUFFY_ACTION_HPP
