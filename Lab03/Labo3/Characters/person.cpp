#include "person.hpp"

#include "../Containers/container.hpp"

const std::string Person::ERROR_MESSAGE = "aucune erreur possible";

Person::~Person() = default;

Person::Person(const std::string &name) : name(name) {}

bool Person::canDrive() const {
    return false;
}

std::string Person::getName() const {
    return name;
}

bool Person::isSafe(const Container &container) const {
    return true;
}

std::string Person::getErrorMessage() const {
    return ERROR_MESSAGE;
}
