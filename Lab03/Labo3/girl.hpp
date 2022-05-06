//
// Created by Alexandre Jaquier on 06.05.2022.
//

#ifndef LABO3_GIRL_HPP
#define LABO3_GIRL_HPP

#include "dependentPerson.hpp"

class Girl : public DependentPerson{
public:
    Girl(const std::string& name,Person& goodWith, Person& badWith);

};


#endif //LABO3_GIRL_HPP
