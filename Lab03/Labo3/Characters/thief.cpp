#include "thief.hpp"
#include "../Containers/container.hpp"

const std::string Thief::ERROR_MESSAGE = "voleur sans policier";

Thief::Thief(const std::string& name, const Person& goodWith) : Person(name) {
    this->dependsOn = &goodWith;
}

/**
 * return true if the police is with the thief and false otherwise
 * @param people
 * @return
 */
bool Thief::isSafe(const Container& container) const{
    if(container.size() == 1){
        return true;
    }
    for (auto it = container.begin(); it != container.end(); ++it) {
        if (*it == this->dependsOn) {
            return true;
        }
    }
    return false;
}

const std::string& Thief::getErrorMessage() const {
    return ERROR_MESSAGE;
}
