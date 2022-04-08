//
// Created by Jonathan on 08.04.2022.
//

#ifndef LABO1_SHIPCHARACTERISTIC_HPP
#define LABO1_SHIPCHARACTERISTIC_HPP


#include <string>

class ShipCharacteristic {
public:
	ShipCharacteristic(const std::string& modele, unsigned maxSpeed, double weight);

	const std::string& getModele() const;

	unsigned int getMaxSpeed() const;

	double getWeight() const;

	unsigned int nextId();


private:
	const std::string modele;
	const unsigned maxSpeed;
	const double weight;
	unsigned int counter;
};


#endif //LABO1_SHIPCHARACTERISTIC_HPP
