//
// Created by Alexandre Jaquier on 05.05.2022.
//

#ifndef LABO3_CHILD_HPP
#define LABO3_CHILD_HPP

#include "person.hpp"
class Child : public Person {
public:
    Child(const std::string& name, bool gender);
private:
    bool gender;

};


#endif //LABO3_CHILD_HPP
