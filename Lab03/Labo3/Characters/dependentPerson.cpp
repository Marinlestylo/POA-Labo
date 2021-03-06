#include "dependentPerson.hpp"
#include "../Containers/container.hpp"

DependentPerson::~DependentPerson() = default;

DependentPerson::DependentPerson(const std::string &name, const Person &dependsOn,
                                 const Person &badWith) : Person(name) {
    this->dependsOn = &dependsOn;
    this->badWith = &badWith;
}

bool DependentPerson::isSafe(const Container &container) const {
    bool isSafe = true;
    for (auto it = container.begin(); it != container.end(); ++it) {
        if (*it == this->dependsOn) {
            isSafe = true;
            break;
        } else if (*it == this->badWith) {
            isSafe = false;
        }
    }
    return isSafe;
}