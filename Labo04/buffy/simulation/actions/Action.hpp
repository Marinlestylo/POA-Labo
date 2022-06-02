//
// Created by Lazar on 19.05.2022.
//

#ifndef BUFFY_ACTION_HPP
#define BUFFY_ACTION_HPP

#include "../Field.hpp"

class Action {
public:
	virtual void execute(Field& f) = 0;
   virtual ~Action() = default;
};


#endif //BUFFY_ACTION_HPP
