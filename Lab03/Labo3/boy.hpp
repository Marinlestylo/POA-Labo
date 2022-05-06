//
// Created by Alexandre Jaquier on 06.05.2022.
//

#ifndef LABO3_BOY_HPP
#define LABO3_BOY_HPP

#include "dependentPerson.hpp"
class Boy : public DependentPerson {
public:
    Boy(const std::string& name, Person& goodWith, Person& badWith);
};


#endif //LABO3_BOY_HPP
