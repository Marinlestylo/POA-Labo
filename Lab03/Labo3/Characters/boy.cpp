#include "boy.hpp"

const std::string Boy::ERROR_MESSAGE = "garcon avec sa mere sans son pere";

Boy::Boy(const std::string &name, const Person &dependsOn, const Person &badWith) :
DependentPerson(name,dependsOn,badWith) {

}

const std::string& Boy::getErrorMessage() const{
    return ERROR_MESSAGE;
}