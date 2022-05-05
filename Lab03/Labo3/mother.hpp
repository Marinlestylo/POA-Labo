//
// Created by Alexandre Jaquier on 05.05.2022.
//

#ifndef LABO3_MOTHER_HPP
#define LABO3_MOTHER_HPP


#include "person.hpp"

class Mother : public Person {
    Mother(const std::string &name);
    bool canDrive() override;

};


#endif //LABO3_MOTHER_HPP
