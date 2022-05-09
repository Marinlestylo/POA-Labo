#include <iostream>
#include <sstream>
#include "container.hpp"

Container::Container(std::string name, std::list<Person *> people) : name(std::move(name)), people(std::move(people)) {}

void Container::showContainer() const {
    std::cout << getName() << " : " << getPeopleNames() << " ";

}

std::string Container::getPeopleNames() const {
    std::stringstream ss;
    for (auto &person : people) {
        ss << person->getName() << " ";
    }
    return ss.str();
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

bool Container::isEmpty() const {
    return people.empty();
}

