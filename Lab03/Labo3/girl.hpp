#ifndef LABO3_GIRL_HPP
#define LABO3_GIRL_HPP

#include "dependentPerson.hpp"

class Girl : public DependentPerson{
public:
    Girl(const std::string& name,Person& goodWith, Person& badWith);
    std::string getErrorMessage() override;

};


#endif //LABO3_GIRL_HPP
