//
// Created by Jonathan on 14.04.2022.
//

#ifndef LABO3_CONTAINER_HPP
#define LABO3_CONTAINER_HPP

#include "person.hpp"
#include <string>
#include <algorithm>
#include <list>

class Container {
public:
    Container(std::string name, std::list<Person*> people);

    Person* contains(Person* person);
    /**
     * Destructeur virtuel pure.
     */
    virtual ~Container() = default;

	 virtual void showContainer() const;

	 const std::string & getName() const;

	 void emptyContainer();

	 void addPerson(Person* p);

	 void removePerson(Person* p);

	 bool isMember(Person* p) const;

	 bool isContainerSafe();

protected:
	std::list<Person*>* getPeople() const;

private:

    std::string name;
    std::list<Person*> people;
};


#endif //LABO3_CONTAINER_HPP
