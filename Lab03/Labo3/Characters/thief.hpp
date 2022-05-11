#ifndef LABO3_THIEF_HPP
#define LABO3_THIEF_HPP


#include "person.hpp"

/**
 * Classe représentant un voleur
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Thief : public Person {
public:
    /**
     * Constructeur de la classe Thief
     * @param name nom du voleur
     * @param goodWith Personne avec qui le voleur peut rester
     */
    Thief(const std::string &name, const Person &goodWith);

    /**
     * Méthode permettant de savoir si la personne est en sécurité dans un lieu
     * @param people liste des personnes présentes dans le lieu
     * @return true si la personne est en sécurité, false sinon
     */
    bool isSafe(const Container &container) const override;

    /**
    * Méthode permettant d'avoir un message d'erreur lié à la personne
    * @return un message d'erreur
    */
    const std::string &getErrorMessage() const override;

private:
    static const std::string ERROR_MESSAGE;
    const Person *dependsOn;
};


#endif //LABO3_THIEF_HPP
