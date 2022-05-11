#include "person.hpp"
#include "../Containers/container.hpp"
Person::Person(const std::string &name) {
    this->name = name;
}

bool Person::canDrive() {
    return false;
}

const std::string &Person::getName() {
    return name;
}

bool Person::isSafe(const Container& container) const{
    return true;
}
