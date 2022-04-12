#ifndef LABO1_TIEHUNTER_HPP
#define LABO1_TIEHUNTER_HPP

#include "ship.hpp"

/**
 * Déclaration de la classe TieHunter héritant de Vaisseau.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class TieHunter : public Ship {
public:

	/**
	 * Constructeur de la classe TieHunter
	 */
	TieHunter();

private:
	static ShipCharacteristic characteristic;
};


#endif //LABO1_TIEHUNTER_HPP
