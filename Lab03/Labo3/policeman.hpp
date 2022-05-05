//
// Created by Alexandre Jaquier on 05.05.2022.
//

#ifndef LABO3_POLICEMAN_HPP
#define LABO3_POLICEMAN_HPP


#include "person.hpp"

class Policeman : public Person {
    Policeman(const std::string & name);
    bool canDrive() override;

};


#endif //LABO3_POLICEMAN_HPP
