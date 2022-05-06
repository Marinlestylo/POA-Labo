//
// Created by Alexandre Jaquier on 05.05.2022.
//

#include "thief.hpp"

Thief::Thief(const std::string& name, Person& goodWith) : Person(name) {
    this->goodWith = &goodWith;
}
