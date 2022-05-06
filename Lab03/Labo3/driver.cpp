//
// Created by Alexandre Jaquier on 06.05.2022.
//

#include "driver.hpp"

Driver::Driver(const std::string &name) : Person(name) {}

bool Driver::canDrive() {
    return true;
}