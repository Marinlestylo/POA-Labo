#ifndef LABO1_DREADNOUGHT_HPP
#define LABO1_DREADNOUGHT_HPP

#include "transporter.hpp"


/**
 * Déclaration de la classe Dreadnought héritant de Transporter.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class Dreadnought : public Transporter {
public:

	/**
	 * Constructeur de la classe Dreadnought
	 * @param load poids de la cargaison
	 */
	explicit Dreadnought(double load);

	/**
	 * Renvoie le poids du vaisseau + le poids de sa cargaison
	 * @return le poids total
	 */
	double getWeight() const override;

private:
	double load;
	static TransporterCharacteristic characteristic;
};


#endif //LABO1_DREADNOUGHT_HPP
