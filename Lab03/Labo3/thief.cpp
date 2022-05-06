//
// Created by Alexandre Jaquier on 05.05.2022.
//

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
    if (people.empty()) {
        return true;
    }

    for (auto person : people) {
        if (person == this->goodWith) {
            return true;
        }
    }
    return false;
}
