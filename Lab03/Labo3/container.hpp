//
// Created by Jonathan on 14.04.2022.
//

#ifndef LABO3_CONTAINER_HPP
#define LABO3_CONTAINER_HPP

#include "person.hpp"
#include <string>
#include <list>

class Container {
public:
    Container(std::string name, std::list<Person*> people);

    /**
     * Pure virtual destructor.
     */
    virtual ~Container() = default;

	 virtual void showContainer() const;

	 const std::string & getName() const;

private:

    std::string name;
    std::list<Person*> people;
};


#endif //LABO3_CONTAINER_HPP
