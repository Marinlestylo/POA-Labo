#ifndef LABO1_SQUADRON_HPP
#define LABO1_SQUADRON_HPP

#include "ship.hpp"

class Squadron;

/**
 * Opérateur de flux de l'escadrille
 * @param os flux d'écriture
 * @param squadron escadrille à écrire
 * @return flux d'écriture
 */
std::ostream &operator<<(std::ostream &os, const Squadron &squadron);

/**
 * Opérateur plus de l'escadrille
 * @param squadron escadrille où ajouter un vaisseau
 * @param ship vaisseau à ajouter
 * @return une copie de l'escadrille avec le vaisseau ajouté
 */
Squadron operator+(const Squadron &squadron, Ship &ship);

/**
 * Opérateur moins de l'escadrille
 * @param squadron escadrille où enlever un vaisseau
 * @param ship vaisseau à enlever
 * @return une copie de l'escadrille avec le vaisseau enlevé
 */
Squadron operator-(const Squadron &squadron, const Ship &ship);

/**
 * Classe permettant de modéliser une escadrille contenant des
 * vaisseaux et potentiellement un chef.
 * @author Alexandre Jaquier
 * @author Jonathan Friedli
 */
class Squadron {
    struct Link {
        Ship *value;
        Link *next;
    };

public:
    /**
     * Constructeur de la classe Squadron
     * @param name nom de l'escadrille
     */
    explicit Squadron(const std::string &name);

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
    Squadron &operator=(const Squadron &other);

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
    Squadron &addShipToSquadron(Ship &ship);

    /**
     * Méthode permettant de retirer un vaisseau de l'escadrille
     * @param ship
     * @return une référence sur l'escadrille
     */
    Squadron &removeShipFromSquadron(const Ship &ship);

    /**
     * Méthode permettant de récupérer un vaisseau de l'escadrille
     * @throws out_of_range si le paramètre est en dehors des index de la liste
     * @param index index du vaisseau dans la liste
     * @return une référence constante sur le vaisseau récupéré
     */
    const Ship &getShip(size_t index) const;

    /**
     * Méthode permettant de récupérer différentes informations sur l'escadrille
     * @param speed vitesse de l'escadrille
     * @param weight poids de l'escadrille
     */
    void squadronInfos(unsigned &speed, double &weight) const;

    /**
     * Méthode retournant une nouvelle escadrille contenant les vaisseaux de
     * l'escadrille appelée et enlevant le vaisseau passé en paramètre
     * @param ship vaisseau à enlever de l'escadrille
     * @return une nouvelle escadrille
     */
    Squadron removeShip(const Ship &ship) const;

    /**
     * Méthode retournant une nouvelle escadrille contenant les vaisseaux de
     * l'escadrille appelée et ajoutant le vaisseau passé en paramètre
     * @param ship vaisseau à ajouter à l'escadrille
     * @return une nouvelle escadrille
     */
    Squadron addShip(Ship &ship) const;

    /**
     * Opérateur permettant de rajouter un vaisseau dans l'escadrille
     * @param ship vaisseau à ajouter
     * @return une référence sur l'escadrille
     */
    Squadron &operator+=(Ship &ship);

    /**
     * Opérateur permettant de retirer un vaisseau de l'escadrille
     * @param ship vaisseau à retirer
     * @return une référence sur l'escadrille
     */
    Squadron &operator-=(const Ship &ship);

    /**
     * Méthode permettant de récupérer la consommation de l'escadrille
     * @param distance distance parcourue
     * @param speed vitesse de l'escadrille
     * @return la consommation de l'escadrille
     */
    double getConsumption(double distance, unsigned speed) const;

    /**
     * Opérateur permettant de récupérer un vaisseau de l'escadrille
     * @throws out_of_range si le paramètre est en dehors des index de la liste
     * @param i index du vaisseau dans la liste
     * @return une référence constante sur le vaisseau récupéré
     */
    const Ship &operator[](size_t i) const;

    /**
     * Permet d'afficher les informations d'une escadrille dans un flux
     * @param os flux dans lequel nous écrivons
     * @return une référence sur le flux modifié
     */
    std::ostream &toStream(std::ostream &os) const;

private:
    /**
     * Méthode permettant d'initialiser les paramètres de l'escadrille
     */
    void initVariables(const std::string &newName, Ship *newLeader, Ship *newHead);

    Ship *leader;
    Link *listHead;
    std::string name;
};


#endif //LABO1_SQUADRON_HPP
