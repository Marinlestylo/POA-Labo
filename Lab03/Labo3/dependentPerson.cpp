//
// Created by Alexandre Jaquier on 05.05.2022.
//

#include "dependentPerson.hpp"

DependentPerson::DependentPerson(const std::string &name, Person& goodWith,
                                 Person& badWith) : Person(name) {
this->goodWith = &goodWith;
this->badWith = &badWith;
}