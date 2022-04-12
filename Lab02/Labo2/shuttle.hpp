/*
-----------------------------------------------------------------------------------
Nom du fichier : shuttle.hpp
Auteur(s)      : Alexandre Jaquier et Jonathan Friedli
Date creation  : 17.03.2022
Description    : Déclaration de la classe shuttle héritant de Transporter.
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO1_SHUTTLE_HPP
#define LABO1_SHUTTLE_HPP

#include "transporter.hpp"
#include "transporterCharacteristic.hpp"

class Shuttle : public Transporter {
public:

	explicit Shuttle(double load);

	double getWeight() const override;

private:
	double load;
	static TransporterCharacteristic characteristic;
};


#endif //LABO1_SHUTTLE_HPP
