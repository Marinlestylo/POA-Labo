#include "dependentPerson.hpp"

DependentPerson::DependentPerson(const std::string &name, Person& goodWith,
                                 Person& badWith) : Person(name) {
    this->dependsOn = &goodWith;
    this->badWith = &badWith;
}

bool DependentPerson::isSafe(const std::list<Person *> &people) const{
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