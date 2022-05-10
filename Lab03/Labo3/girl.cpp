#include "girl.hpp"

const std::string Girl::ERROR_MESSAGE = "fille avec son pere sans sa mere";

Girl::Girl(const std::string &name, Person &goodWith, Person &badWith) :
DependentPerson(name,goodWith,badWith) {

}

std::string Girl::getErrorMessage() {
    return Girl::ERROR_MESSAGE;
}