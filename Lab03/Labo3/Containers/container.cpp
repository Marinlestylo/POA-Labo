#include <iostream>
#include <sstream>
#include <utility>
#include "container.hpp"
#include "../controller.hpp"
#include "../Characters/person.hpp"

Container::Container(std::string name, std::list<Person *>& people) : name
(std::move(name)), people(people) {}

std::ostream& Container::toStream(std::ostream& os) const {
    return os << getName() << " : " << getPeopleNames() << " ";
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
    people.clear();
}

void Container::addPerson(Person& p) {
    if(isFull()){
        throw std::runtime_error("le container est plein");
    }
	people.push_back(&p);
}

void Container::removePerson(Person& p) {
    if(people.empty()){
        throw new std::runtime_error("Le container est vide");
    }
	people.remove(&p);
}

std::list<Person*>* Container::getPeople() const {
	return (std::list<Person*>*) &people;
}

bool Container::isMember(const Person& p) const {
	return std::find(people.begin(), people.end(), &p) != people.end();
}

bool Container::isContainerSafe() {
	for(Person* p : people){
		if(!p->isSafe(*this)){
            Controller::showError(p->getErrorMessage());
			return false;
		}
	}
	return true;
}

bool Container::isEmpty() const {
    return people.empty();
}

bool Container::isFull() const {
    return false;
}

std::list<Person *>::const_iterator Container::begin() const {
    return people.cbegin();
}

std::list<Person *>::const_iterator Container::end() const {
    return people.cend();
}

int Container::size() const {
    return people.size();
}

