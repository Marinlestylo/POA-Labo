//
// Created by Jonathan on 14.04.2022.
//

#include <iostream>
#include "container.hpp"

Container::Container(std::string name, std::list<Person *> people) : name(std::move(name)), people(std::move(people)) {

}

void Container::showContainer() const {
	for(Person* p: people){
		std::cout << p->getName() << " ";
	}
}

const std::string& Container::getName() const {
	return name;
}
