//
// Created by Jonathan on 14.04.2022.
//

#ifndef LABO3_PERSON_HPP
#define LABO3_PERSON_HPP

#include <list>
#include "string"

class Person {
public:
    Person(const std::string& name);
    virtual bool canDrive();
    const std::string& getName();
    virtual bool isSafe(const std::list<Person*>& people);

private:
    std::string name;
};


#endif //LABO3_PERSON_HPP
