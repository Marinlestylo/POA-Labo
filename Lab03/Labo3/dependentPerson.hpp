#ifndef LABO3_DEPENDENTPERSON_HPP
#define LABO3_DEPENDENTPERSON_HPP


#include "person.hpp"
#include <algorithm>

class DependentPerson : public Person {

public:
    DependentPerson(const std::string& name, Person& goodWith, Person& badWith);
    bool isSafe(const std::list<Person *> &people) override;
    virtual std::string getErrorMessage() = 0;
private:
    Person* dependsOn;
    Person* badWith;
};


#endif //LABO3_DEPENDENTPERSON_HPP
