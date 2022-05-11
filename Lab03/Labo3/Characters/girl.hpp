#ifndef LABO3_GIRL_HPP
#define LABO3_GIRL_HPP

#include "dependentPerson.hpp"

/**
 * Classe représentant la classe Girl
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Girl : public DependentPerson{
public:

    /**
     * Constructeur de la classe Girl
     * @param name nom de la personne
     * @param dependsOn personne dont la personne dépend
     * @param badWith personne avec laquelle elle ne peut pas rester
     */
    Girl(const std::string& name,const Person& dependsOn, const Person& badWith);

    /**
     * Méthode permettant d'avoir un message d'erreur lié à la personne
     * @return un message d'erreur
     */
    const std::string& getErrorMessage()const override;
private:
    static const std::string ERROR_MESSAGE;
};


#endif //LABO3_GIRL_HPP
