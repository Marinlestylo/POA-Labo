#ifndef SHIP_HPP
#define SHIP_HPP

#include <ostream>
#include "shipCharacteristic.hpp"

class Ship;

/**
 * Surcharge de l'opérateur d'écriture dans un flux afin d'y écrire les informations d'un vaisseau. Fait appel à la
 * méthode toStream
 * @param os flux dans lequel on écrit
 * @param ship Vaisseaux dont nous allons afficher les informations
 * @return une référence sur l'opérateur de flux
 */
std::ostream& operator<<(std::ostream& os, const Ship& ship);

/**
 * Classe modélisant toutes sorte de vaisseaux spatiaux.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class Ship {
public:

	/**
	 * Constructeur de la classe vaisseau
	 * @param id id du vaisseau
	 */
	explicit Ship(unsigned int id, ShipCharacteristic* characteristic);

	/**
	 * Destructeur de la classe vaisseau
	 */
	virtual ~Ship() = default;

	/**
	 * Permet d'afficher les informations d'un vaisseau dans un flux
	 * @param os flux dans lequel nous écrivons
	 * @return une référence sur le flux modifié
	 */
	virtual std::ostream& toStream(std::ostream& os) const;

	/**
	 * Permet de modifier le nickname du vaisseau
	 * @param name nouveau nom
	 */
	void setNickname(const std::string& name);

	/**
	 * Renvoie le poids du vaisseau en tonne
	 * @return le poids en tonne
	 */
	virtual double getWeight() const;

	unsigned int getMaxSpeed() const;

	/**
	 * Calcule la consommation d'un vaisseau compte tenu de sa vitesse, de la distance du trajet et de son chargement
	 * @throws runtime_error si la vitesse voulue n'est pas atteignable par le
	 * vaisseau
	 * @param distance Distance parcourue en millions de km
	 * @param speed Vitesse à laquelle le vaisseau avance
	 * @return La consomation en tonne
	 */
	double getConsumption(double distance, unsigned speed) const;

private:
	/**
	 * Construit un string représentant l'identité du vaisseau sous la forme "[<modèle> #<id>]"
	 * @return l'identité du vaisseau
	 */
	std::string getIdentity() const;

	std::string nickname;
	unsigned int id;
	const ShipCharacteristic* characteristic;
};

#endif /* SHIP_HPP */
