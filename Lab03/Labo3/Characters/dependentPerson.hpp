#ifndef LABO3_DEPENDENTPERSON_HPP
#define LABO3_DEPENDENTPERSON_HPP

#include "person.hpp"
#include <algorithm>

/**
 * Classe représentant une personne dépendante de deux autre
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class DependentPerson : public Person {
protected:
    /**
    * Constructeur de la classe DependentPerson
    * @param name nom de la personne
    * @param dependsOn personne de qui la personne dépend
    * @param badWith personne avec laquelle elle ne peut pas rester
    */
    DependentPerson(const std::string &name, const Person &dependsOn, const Person &
    badWith);

public:
    /**
     * Destructeur de la classe DependentPerson
     */
    ~DependentPerson() = 0;

    /**
     * Méthode permettant de savoir si la personne est en sécurité dans un lieu
     * @param people liste des personnes présentes dans le lieu
     * @return true si la personne est en sécurité, false sinon
     */
    bool isSafe(const Container &container) const override;

private:
    const Person *dependsOn;
    const Person *badWith;
};


#endif //LABO3_DEPENDENTPERSON_HPP
