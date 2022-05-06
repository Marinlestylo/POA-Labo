//
// Created by Alexandre Jaquier on 05.05.2022.
//

#ifndef LABO3_DEPENDENTPERSON_HPP
#define LABO3_DEPENDENTPERSON_HPP


#include "person.hpp"

class DependentPerson : public Person {

public:
    DependentPerson(const std::string& name, Person& goodWith, Person& badWith);
private:
    Person* goodWith;
    Person* badWith;
};


#endif //LABO3_DEPENDENTPERSON_HPP
