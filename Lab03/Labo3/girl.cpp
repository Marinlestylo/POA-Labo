//
// Created by Alexandre Jaquier on 06.05.2022.
//

#include "girl.hpp"

Girl::Girl(const std::string &name, Person &goodWith, Person &badWith) :
DependentPerson(name,goodWith,badWith) {

}

std::string Girl::getErrorMessage() {
    return getName() + " sans sa mere avec son pere";
}