#include "girl.hpp"

const std::string Girl::ERROR_MESSAGE = "fille avec son pere sans sa mere";

Girl::Girl(const std::string &name, Person &dependsOn, Person &badWith) :
DependentPerson(name,dependsOn,badWith) {

}

std::string Girl::getErrorMessage() {
    return ERROR_MESSAGE;
}