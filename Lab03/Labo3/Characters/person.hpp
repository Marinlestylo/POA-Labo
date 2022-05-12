#ifndef LABO3_PERSON_HPP
#define LABO3_PERSON_HPP

#include <list>
#include <string>

class Container;
/**
 * Classe représentant une personne
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Person {
protected:
    /**
    * Constructeur de la classe Person
    * @param name nom de la personne
    */
    explicit Person(const std::string& name);

public:
    /**
     * Destructeur de la classe Person
     */
    virtual ~Person() = 0;

    /**
     * Méthode permettant de savoir si la personne peut conduire
     * @return true si la personne peut conduire, false sinon
     */
    virtual bool canDrive() const;

    /**
     * Méthode permettant de connaitre le nom de la personne
     * @return le nom de la personne
     */
    std::string getName() const;

    /**
     * Méthode permettant de savoir si la personne est en sécurité dans un lieu
     * @param people liste des personnes présentes dans le lieu
     * @return true si la personne est en sécurité, false sinon
     */
    virtual bool isSafe(const Container& container) const;

    /**
     * Méthode permettant d'avoir un message d'erreur lié à la personne
     * @return un message d'erreur
     */
    virtual std::string getErrorMessage() const;

private:
    const std::string name;
    static const std::string ERROR_MESSAGE;
};


#endif //LABO3_PERSON_HPP
