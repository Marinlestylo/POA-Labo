#ifndef LABO3_PERSON_HPP
#define LABO3_PERSON_HPP

#include <list>
#include "string"

/**
 * Classe représentant une personne
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Person {
public:
    /**
     * Constructeur de la classe Person
     * @param name nom de la personne
     */
    explicit Person(const std::string& name);

    /**
     * Destructeur de la classe Person
     */
    virtual ~Person() = default;
    /**
     * Méthode permettant de savoir si la personne peut conduire
     * @return true si la personne peut conduire, false sinon
     */
    virtual bool canDrive();

    /**
     * Méthode permettant de connaitre le nom de la personne
     * @return le nom de la personne
     */
    const std::string& getName();

    /**
     * Méthode permettant de savoir si la personne est en sécurité dans un lieu
     * @param people liste des personnes présentes dans le lieu
     * @return true si la personne est en sécurité, false sinon
     */
    virtual bool isSafe(const std::list<Person*>& people);

    /**
     * Méthode permettant d'avoir un message d'erreur lié à la personne
     * @return un message d'erreur
     */
    virtual std::string getErrorMessage() = 0;

private:
    std::string name;
};


#endif //LABO3_PERSON_HPP
