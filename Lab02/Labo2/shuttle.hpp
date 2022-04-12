#ifndef LABO1_SHUTTLE_HPP
#define LABO1_SHUTTLE_HPP

#include "transporter.hpp"
#include "transporterCharacteristic.hpp"

/**
 * Déclaration de la classe shuttle héritant de Transporter.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class Shuttle : public Transporter {
public:

	/**
	 * Constructeur de la classe Shuttle
	 * @param load poids de la cargaison
	 */
	explicit Shuttle(double load);

	/**
	 * Renvoie le poids du vaisseau + celui de sa cargaison
	 * @return le poids total
	 */
	double getWeight() const override;

private:
	double load;
	static TransporterCharacteristic characteristic;
};


#endif //LABO1_SHUTTLE_HPP
