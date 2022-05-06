//
// Created by Alexandre Jaquier on 05.05.2022.
//

#ifndef LABO3_THIEF_HPP
#define LABO3_THIEF_HPP


#include "person.hpp"

class Thief : public Person {
public:
    Thief(const std::string& name, Person& goodWith);
private:
    Person* goodWith;
};


#endif //LABO3_THIEF_HPP
