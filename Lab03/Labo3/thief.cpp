//
// Created by Alexandre Jaquier on 05.05.2022.
//

#include <iostream>
#include "thief.hpp"

Thief::Thief(const std::string& name, Person& goodWith) : Person(name) {
    this->goodWith = &goodWith;
}

/**
 * return true if the police is with the thief and false otherwise
 * @param people
 * @return
 */
bool Thief::isSafe(const std::list<Person *> &people) {
    if (people.size() == 1) {
        return true;
    }

    for (auto person : people) {
        if (person == this->goodWith) {
            return true;
        }
    }
    std::cout << getErrorMessage() << std::endl;
    return false;
}

std::string Thief::getErrorMessage() {
    return "voleur sans policier";
}
