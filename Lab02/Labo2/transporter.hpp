/*
-----------------------------------------------------------------------------------
Nom du fichier : transporter.hpp
Auteur(s)      : Alexandre Jaquier et Jonathan Friedli
Date creation  : 17.03.2022
Description    : Déclaration de la classe Transporter héritant de Ship et
                 modélisant des vaisseaux transportant des cargaisons.
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO1_TRANSPORTER_HPP
#define LABO1_TRANSPORTER_HPP

#include "ship.hpp"

class Transporter : public Ship {
public:

	Transporter(unsigned int id, double currentLoad, double maxLoad);

	double getLoad() const;

	void setLoad(double load);

	virtual double getMaxLoad() const = 0;

	std::ostream& toStream(std::ostream& os) const override;

private:
	double currentLoad;
};


#endif //LABO1_TRANSPORTER_HPP
