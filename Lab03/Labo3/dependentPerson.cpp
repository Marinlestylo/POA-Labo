#include <iostream>
#include "dependentPerson.hpp"

DependentPerson::DependentPerson(const std::string &name, Person& goodWith,
                                 Person& badWith) : Person(name) {
    this->dependsOn = &goodWith;
    this->badWith = &badWith;
}

/**
 * return true if is with the good person and false if is with the bad person alone
 * @param people list of people
 * @return true if is with the good person and false if is with the bad person alone
 */
bool DependentPerson::isSafe(const std::list<Person *> &people) {
    bool isSafe = true;
    for (auto &person : people) {
        if (person == this->dependsOn) {
            isSafe = true;
            break;
        }else if(person == this->badWith) {
            isSafe = false;
        }
    }
    return isSafe;
}