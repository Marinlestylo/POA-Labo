/*
-----------------------------------------------------------------------------------
Nom du fichier : ship.hpp
Auteur(s)      : Alexandre Jaquier et Jonathan Friedli
Date creation  : 17.03.2022
Description    : Déclaration de la classe Ship modélisant toutes sorte de
                 vaisseaux spatiaux.
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef SHIP_HPP
#define SHIP_HPP

#include <ostream>

class Ship;

std::ostream& operator<<(std::ostream& os, const Ship& ship);

class Ship {
public:

	Ship(unsigned int id);

	virtual ~Ship() = default;

	virtual std::ostream& toStream(std::ostream& os) const;

	void setNickname(const std::string& name);

	virtual double getWeight() const = 0;

	virtual const std::string& getModele() const = 0;

	virtual unsigned int getSpeed() const = 0;

	virtual double getConsomation(double distance, unsigned speed) const;

private:
	std::string getIdentity() const;

	std::string nickname;
    unsigned int id;
};

#endif /* SHIP_HPP */
