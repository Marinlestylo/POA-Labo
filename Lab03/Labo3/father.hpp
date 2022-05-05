//
// Created by Alexandre Jaquier on 05.05.2022.
//

#ifndef LABO3_FATHER_HPP
#define LABO3_FATHER_HPP


#include "person.hpp"

class Father : public Person {
    Father(const std::string& name);
    bool canDrive() override
};


#endif //LABO3_FATHER_HPP
