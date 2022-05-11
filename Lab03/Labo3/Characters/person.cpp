#include "person.hpp"

#include "../Containers/container.hpp"

const std::string Person::ERROR_MESSAGE = "aucune erreur possible";

Person::Person(const std::string &name) : name(name) {
}

bool Person::canDrive() const {
    return false;
}

const std::string &Person::getName() const {
    return name;
}

bool Person::isSafe(const Container &container) const {
    return true;
}

const std::string &Person::getErrorMessage() const {
    return "";
}
