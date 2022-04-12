/*
-----------------------------------------------------------------------------------
Nom du fichier : dreadnought.hpp
Auteur(s)      : Alexandre Jaquier et Jonathan Friedli
Date creation  : 17.03.2022
Description    : Déclaration de la classe dreadnought héritant de Transporter.
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO1_DREADNOUGHT_HPP
#define LABO1_DREADNOUGHT_HPP

#include "transporter.hpp"

class Dreadnought : public Transporter {
public:

	explicit Dreadnought(double load);

	double getWeight() const override;

private:
	double load;
	static TransporterCharacteristic characteristic;
};


#endif //LABO1_DREADNOUGHT_HPP
