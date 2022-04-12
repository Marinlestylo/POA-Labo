#ifndef LABO1_SQUADRON_HPP
#define LABO1_SQUADRON_HPP

#include "ship.hpp"

class Squadron;

std::ostream &operator<<(std::ostream &os, const Squadron &squadron);

Squadron operator+(const Squadron &squadron, Ship &ship);

Squadron operator-(const Squadron &squadron, Ship &ship);

/**
* Classe permettant de modéliser une escadrille contenant des
* vaisseaux et potentiellement un chef.
*/
class Squadron {
    struct Maillon {
        Ship *valeur;
        Maillon *suivant;
    };

    friend std::ostream &operator<<(std::ostream &os, const Squadron &squadron);

public:
    /**
     * Constructeur de la classe Squadron
     * @param name nom de l'escadrille
     */
    Squadron(const std::string& name);

    /**
    * Constructeur par copie de la classe Squadron
    * @param other escadrille à copier
    */
    Squadron(const Squadron &other);

    /**
    * Déstructeur de la classe Squadron
    */
    ~Squadron();

    /**
    * Opérateur d'affectation de l'escadrille, copie tous les vaisseaux ainsi que
     * le nom et le chef d'escadrille
    * @param other
    * @return
    */
    Squadron &operator=(const Squadron& other);

    /**
    * Méthode permettant de définir le chef de l'escadrille, si le vaisseau ne fait
    * pas parti des membres de l'escadrille il y est ajouté
    * @param newLeader chef de l'escadrille
    */
    void setLeader(Ship &newLeader);

    /**
     * Méthode permettant de rajouter un vaisseau dans l'escadrille
     * @param ship
     * @return une référence sur l'escadrille
     */
    Squadron &addShipFromSquadron(Ship &ship);

    /**
     * Méthode permettant de retirer un vaisseau de l'escadrille
     * @param ship
     * @return une référence sur l'escadrille
     */
    Squadron &removeShipFromSquadron(const Ship &ship);

    /**
     * Méthode permettant de récupérer un vaisseau de l'escadrille
     * @throws out_of_range si le paramètre est en dehors des index de la liste
     * @param i index du vaisseau dans la liste
     * @return une référence constante sur le vaisseau récupéré
     */
    const Ship &getShip(size_t i) const;

    void squadronInfos(unsigned& speed, double& weight) const;

    Squadron removeShip(const Ship &ship) const;

    Squadron addShip(Ship &ship) const;

    Squadron &operator+=(Ship &ship);

    Squadron &operator-=(const Ship &ship);

    double getConsommation(double distance, unsigned speed) const;

    /**
     * Opérateur permettant de récupérer un vaisseau de l'escadrille
     * @throws out_of_range si le paramètre est en dehors des index de la liste
     * @param i index du vaisseau dans la liste
     * @return une référence constante sur le vaisseau récupéré
     */
    const Ship &operator[](size_t i) const;

private:

    void initVariables(const std::string& newName, Ship *newLeader,Ship* newHead);
    Ship *leader;
    Maillon *listHead;
    Maillon *listTail;
    std::string name;
};


#endif //LABO1_SQUADRON_HPP
