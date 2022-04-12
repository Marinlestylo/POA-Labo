#ifndef LABO1_TRANSPORTERCHARACTERISTIC_HPP
#define LABO1_TRANSPORTERCHARACTERISTIC_HPP


#include "shipCharacteristic.hpp"

/**
 * Classe héritant de shipCharacteristic permettant de modéliser le poids maximal de
 * la cargaison d'un vaisseau
 */
class TransporterCharacteristic : public ShipCharacteristic {
public:
	/**
	 * Constructeur de la classe TransporterCharacteristic
	 * @param modele Modèle du vaisseau
	 * @param maxSpeed Vitesse max du vaisseau
	 * @param weight Poids du vaisseau
	 * @param maxLoad Poids maximal de la cargaison
	 */
	TransporterCharacteristic(const std::string& modele, unsigned maxSpeed,
									  double weight, double maxLoad);

	/**
	 * Renvoie le poids maximal de la cargaison
	 * @return le poids max
	 */
	double getMaxLoad() const;

private:
	double maxLoad;
};


#endif //LABO1_TRANSPORTERCHARACTERISTIC_HPP
