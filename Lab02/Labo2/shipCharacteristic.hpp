#ifndef LABO1_SHIPCHARACTERISTIC_HPP
#define LABO1_SHIPCHARACTERISTIC_HPP


#include <string>

/**
 * Classe modélisant les différentes caractéristiques d'un vaisseau spatial telle
 * que sa vitesse maximale, son modèle et son poids.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class ShipCharacteristic {
public:
    /**
     * Constructeur de la classe ShipCharacteristic
     * @param modele modele du vaisseau
     * @param maxSpeed Vitesse maximale en MGLT
     * @param weight poids du vaisseau en tonne
     */
    ShipCharacteristic(const std::string &modele, unsigned maxSpeed, double weight);

    /**
     * Renvoie le modèle du vaisseau
     * @return le modèle
     */
    const std::string &getModele() const;

    /**
     * Renvoie la vitesse max du vaisseau en MGLT
     * @return la vitesse max en MGLT
     */
    unsigned int getMaxSpeed() const;

    /**
     * Renvoie le poids du vaisseau en tonne
     * @return le poids en tonne
     */
    double getWeight() const;

    /**
     * Permet de générer un id dépendant du type du vaisseau
     * @return le prochain id utilisable
     */
    unsigned int nextId();


private:
    const std::string modele;
    const unsigned maxSpeed;
    const double weight;
    unsigned int counter;
};


#endif //LABO1_SHIPCHARACTERISTIC_HPP
