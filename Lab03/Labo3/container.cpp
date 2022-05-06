//
// Created by Jonathan on 14.04.2022.
//

#include <iostream>
#include "container.hpp"

Container::Container(std::string name, std::list<Person *> people) : name(std::move(name)), people(std::move(people)) {}

Person * Container::contains(Person *person) {
    Person* found = nullptr;
    if(std::find(people.begin(), people.end(), person) != people.end()) {
        found = person;
    }
    return found;
}

void Container::showContainer() const {
	for(Person* p: people){
		std::cout << p->getName() << " ";
	}
}

const std::string& Container::getName() const {
	return name;
}

void Container::emptyContainer() {
	while(!people.empty()){
		people.pop_front();
	}
}

void Container::addPerson(Person* p) {
	people.push_back(p);
}

void Container::removePerson(Person* p) {
	people.remove(p);
}

std::list<Person*>* Container::getPeople() const {
	return (std::list<Person*>*) &people;
}

bool Container::isMember(Person* p) const {
	return std::find(people.begin(), people.end(), p) != people.end();
}

bool Container::isContainerSafe() {
	for(Person* p : people){
		if(!p->isSafe(people)){
			return false;
		}
	}
	return true;
}
