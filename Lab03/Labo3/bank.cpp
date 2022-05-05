//
// Created by Jonathan on 14.04.2022.
//

#include <iostream>
#include "bank.hpp"

Bank::Bank(std::string name, std::list<Person *> people) : Container(std::move(name), std::move(people)) {
}

void Bank::showContainer() const {
	std::cout << Container::getName() << " : ";
	Container::showContainer();
}
