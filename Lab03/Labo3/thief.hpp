#ifndef LABO3_THIEF_HPP
#define LABO3_THIEF_HPP


#include "person.hpp"

class Thief : public Person {
public:
    Thief(const std::string& name, Person& goodWith);
    bool isSafe(const std::list<Person *> &people) override;

    std::string getErrorMessage();
private:
    Person* dependsOn;
};


#endif //LABO3_THIEF_HPP
