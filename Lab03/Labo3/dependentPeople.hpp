//
// Created by Alexandre Jaquier on 05.05.2022.
//

#ifndef LABO3_DEPENDENTPEOPLE_HPP
#define LABO3_DEPENDENTPEOPLE_HPP


#include "person.hpp"

class DependentPeople : public Person {

public:
    DependentPeople(const std::string& name, Person* goodWith,Person* badWith);
private:
    Person* goodWith;
    Person* badWith;
};


#endif //LABO3_DEPENDENTPEOPLE_HPP
