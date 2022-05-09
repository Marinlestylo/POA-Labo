#include "boy.hpp"

Boy::Boy(const std::string &name, Person &goodWith, Person &badWith) :
DependentPerson(name,goodWith,badWith) {

}

std::string Boy::getErrorMessage() {
    return getName() + " sans son pere avec sa mere";
}