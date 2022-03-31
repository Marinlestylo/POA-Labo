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

	const std::string& getModele() const override;

	unsigned int getId() const override;

	double getWeight() const override;

	unsigned int getSpeed() const override;

	double getMaxLoad() const override;

private:
	const static std::string modele;
	const static unsigned int speed;
	const static unsigned long long weight;
	const static double maxLoad;
	static unsigned int counter;
	unsigned int id;
};


#endif //LABO1_DREADNOUGHT_HPP
