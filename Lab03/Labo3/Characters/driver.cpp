#include "driver.hpp"

Driver::Driver(const std::string &name) : Person(name) {}

bool Driver::canDrive() {
    return true;
}

std::string Driver::getErrorMessage() {
    return "";
}
