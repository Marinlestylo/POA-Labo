//
// Created by Alexandre Jaquier on 05.05.2022.
//

#ifndef LABO3_PARENT_HPP
#define LABO3_PARENT_HPP

#include "person.hpp"
class Parent : public Person {
public :
    Parent(const std::string &name, bool gender);
    bool canDrive() override{
        return true;
    }
private:
    bool gender;
};


#endif //LABO3_PARENT_HPP
