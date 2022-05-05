//
// Created by Jonathan on 14.04.2022.
//

#include "container.hpp"

Container::Container(std::string name, std::list<Person *> people) : name(std::move(name)), people(std::move(people)) {

}
