#include "boy.hpp"

const std::string Boy::ERROR_MESSAGE = "garcon avec sa mere sans son pere";

Boy::Boy(const std::string &name, Person &goodWith, Person &badWith) :
DependentPerson(name,goodWith,badWith) {

}

std::string Boy::getErrorMessage() {
    return Boy::ERROR_MESSAGE;
}