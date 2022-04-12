#ifndef LABO1_TIEINTERCEPTOR_HPP
#define LABO1_TIEINTERCEPTOR_HPP

#include "ship.hpp"

/**
 * Déclaration de la classe TieInterceptor héritant de Vaisseau.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class TieInterceptor : public Ship {
public:

	/**
	 * Constructeur de la classe TieInterceptor
	 */
	TieInterceptor();

private:

	static ShipCharacteristic characteristic;
};


#endif //LABO1_TIEINTERCEPTOR_HPP
