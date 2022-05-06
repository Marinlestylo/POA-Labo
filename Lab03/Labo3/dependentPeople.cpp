//
// Created by Alexandre Jaquier on 05.05.2022.
//

#include "dependentPeople.hpp"

DependentPeople::DependentPeople(const std::string &name, Person* goodWith,
                                 Person* badWith) : Person(name), goodWith
                                 (goodWith), badWith(badWith) {}