#include "boy.hpp"

const std::string Boy::ERROR_MESSAGE = "garcon avec sa mere sans son pere";

Boy::Boy(const std::string &name, Person &dependsOn, Person &badWith) :
DependentPerson(name,dependsOn,badWith) {

}

std::string Boy::getErrorMessage() {
    return Boy::ERROR_MESSAGE;
}