#ifndef LABO1_TRANSPORTER_HPP
#define LABO1_TRANSPORTER_HPP

#include "ship.hpp"
#include "cargoCharacteristic.hpp"

/**
 * Déclaration de la classe Transporter héritant de Ship et modélisant des vaisseaux transportant des cargaisons.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class Transporter : public Ship {
public:

	/**
	 * Constructeur de la classe Transporteur
	 * @param id id du vaisseau
	 * @param currentLoad poids de la cargaison courante
	 * @param maxLoad poids maximal du vaisseau
	 */
	Transporter(unsigned int id, double currentLoad, CargoCharacteristic*
	characteristic);

	/**
	 * Renvoie le poids de la cargaison courrante
	 * @return le poids de la cargaison
	 */
	double getLoad() const;

	/**
	 * Permet de mettre à jours le poids de la cargaison
	 * @param load nouveau poids
	 */
	void setLoad(double load);

	/**
	 * Renvoie le poids maximal de cargaison que le vaisseau peut supporter
	 * @return poids maximal
	 */
	virtual double getMaxLoad() const = 0;

	/**
	 * Redéfinition de la fonction toStream. Elle affiche les informations du vaisseau dans un flux
	 * @param os flux d'écriture dans lequel on écrit
	 * @return Une référence sur le flux modifié
	 */
	std::ostream& toStream(std::ostream& os) const override;

private:
	double currentLoad;
	CargoCharacteristic* characteristic;
};


#endif //LABO1_TRANSPORTER_HPP
