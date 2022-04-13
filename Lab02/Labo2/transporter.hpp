#ifndef LABO1_TRANSPORTER_HPP
#define LABO1_TRANSPORTER_HPP

#include "ship.hpp"
#include "transporterCharacteristic.hpp"

/**
 * Déclaration de la classe Transporter héritant de Ship et modélisant des vaisseaux transportant des cargaisons.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class Transporter : public Ship {
protected:
	/**
	 * Constructeur de la classe Transporter
	 * @param id id du vaisseau
	 * @param currentLoad poids de la cargaison
	 * @param characteristic Pointeur sur les caractéristique d'un vaisseau pouvant
	 * transporter une cargaison
	 */
	Transporter(unsigned int id, double currentLoad, TransporterCharacteristic*
	characteristic);
public:
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
	 * Redéfinition de la fonction toStream. Elle affiche les informations du vaisseau dans un flux
	 * @param os flux d'écriture dans lequel on écrit
	 * @return Une référence sur le flux modifié
	 */
	std::ostream& toStream(std::ostream& os) const override;

    /**
	 * Renvoie le poids du vaisseau + celui de sa cargaison
	 * @return le poids total
	 */
    double getWeight() const override;

private:
	double currentLoad;
	TransporterCharacteristic* characteristic;
};


#endif //LABO1_TRANSPORTER_HPP
