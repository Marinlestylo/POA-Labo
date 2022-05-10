#include "thief.hpp"

const std::string Thief::ERROR_MESSAGE = "voleur sans policier";

Thief::Thief(const std::string& name, Person& goodWith) : Person(name) {
    this->dependsOn = &goodWith;
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
        if (person == this->dependsOn) {
            return true;
        }
    }
    return false;
}

std::string Thief::getErrorMessage() {
    return Thief::ERROR_MESSAGE;
}
