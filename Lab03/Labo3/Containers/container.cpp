#include <iostream>
#include <sstream>
#include "container.hpp"
#include "../controller.hpp"

Container::Container(const std::string &name) : name(name) {}

std::ostream &Container::toStream(std::ostream &os) const {
    return os << getName() << " : " << getPeopleNames() << " ";
}

std::string Container::getPeopleNames() const {
    std::stringstream ss;
    for (auto &person: people) {
        ss << person->getName() << " ";
    }
    return ss.str();
}

const std::string &Container::getName() const {
    return name;
}

void Container::emptyContainer() {
    people.clear();
}

void Container::addPerson(const Person &p) {
    if (isFull()) {
        throw std::runtime_error("le container est plein");
    }
    people.push_back(&p);
}

void Container::removePerson(const Person &p) {
    if (people.empty()) {
        throw new std::runtime_error("Le container est vide");
    }
    people.remove(&p);
}

bool Container::isMember(const Person &p) const {
    return std::find(people.begin(), people.end(), &p) != people.end();
}

bool Container::isContainerSafe() const {
    for (const Person *p: people) {
        if (!p->isSafe(*this)) {
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

std::list<const Person *>::const_iterator Container::begin() const {
    return people.cbegin();
}

std::list<const Person *>::const_iterator Container::end() const {
    return people.cend();
}

unsigned Container::size() const {
    return people.size();
}

void Container::addAll(const std::list<const Person *> &peopleToAdd) {
    for (const Person *p: peopleToAdd) {
        if (isFull())
            throw std::runtime_error("le container est plein");
        this->people.push_back(p);
    }
}

