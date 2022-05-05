//
// Created by Jonathan on 14.04.2022.
//

#ifndef LABO3_BANK_HPP
#define LABO3_BANK_HPP

#include "container.hpp"

class Bank : public Container {
public:
    Bank(std::string name, std::list<Person *> people);

};


#endif //LABO3_BANK_HPP
