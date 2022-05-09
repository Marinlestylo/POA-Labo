#include "person.hpp"

Person::Person(const std::string &name) {
    this->name = name;
}

bool Person::canDrive() {
    return false;
}

const std::string &Person::getName() {
    return name;
}

bool Person::isSafe(const std::list<Person *> &people) {
    return true;
}
