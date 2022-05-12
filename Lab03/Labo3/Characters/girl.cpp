#include "girl.hpp"

const std::string Girl::ERROR_MESSAGE = "fille avec son pere sans sa mere";

Girl::Girl(const std::string &name,const Person &dependsOn,const Person &badWith) :
DependentPerson(name,dependsOn,badWith) {}

std::string Girl::getErrorMessage() const {
    return ERROR_MESSAGE;
}