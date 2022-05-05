//
// Created by Alexandre Jaquier on 05.05.2022.
//

#include "policeman.hpp"
Policeman::Policeman(const std::string& name) : Person(name) {}

bool Policeman::canDrive() {
    return true;
}