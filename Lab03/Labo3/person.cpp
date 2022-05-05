//
// Created by Jonathan on 14.04.2022.
//

#include "person.hpp"

Person::Person(const std::string& name) {
    this->name = name;
}

bool Person::canDrive() {
    return false;
}

const std::string &Person::getName() {
    return name;
}
