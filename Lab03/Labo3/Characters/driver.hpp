#ifndef LABO3_DRIVER_HPP
#define LABO3_DRIVER_HPP


#include "person.hpp"

/**
 * Classe représentant les conducteurs
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Driver : public Person {
public:
    /**
     * Constructeur de la classe Driver
     * @param name nom du conducteur
     */
    explicit Driver(const std::string & name);

    /**
     * Méthode permettant de savoir si la personne peut conduire
     * @return true si la personne peut conduire, false sinon
     */
    bool canDrive() const override;
};


#endif //LABO3_DRIVER_HPP
