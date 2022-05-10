#ifndef LABO3_BOY_HPP
#define LABO3_BOY_HPP

#include "dependentPerson.hpp"
class Boy : public DependentPerson {
public:
    Boy(const std::string& name, Person& goodWith, Person& badWith);
    std::string getErrorMessage() override;
private:
    static const std::string ERROR_MESSAGE;
};


#endif //LABO3_BOY_HPP
