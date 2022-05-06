//
// Created by Jonathan on 14.04.2022.
//

#include <iostream>
#include "boat.hpp"

const std::string Boat::RIVER =
	"==============================================================================";

Boat::Boat(Bank* current) : Container("Bateau", std::list<Person *>()),
									 currentBank(current) { }

void Boat::showContainer() const {
	if(currentBank->getName() == "gauche"){
		std::cout << Container::getName() << " : " << "< ";
		Container::showContainer();
		std::cout << " >" << std::endl << RIVER << std::endl;
	} else{
		std::cout << std::endl << RIVER << std::endl << Container::getName()
		<< " : " << "< ";
		Container::showContainer();
		std::cout << " >";
	}
}

void Boat::moveBoat(Bank* bank) {
	bool hasDriver = false;
	for(Person* p : *Container::getPeople()){
		if(p->canDrive()){
			hasDriver = true;
		}
	}
	if(!hasDriver){
		std::cout << "Il n'y a pas de conducteur dans le bateau" << std::endl;
		return;
	}
	currentBank = bank;

}

Bank* Boat::getBank() const {
	return currentBank;
}

bool Boat::isDockedOnthisBank(Bank* bank) const {
	return bank == currentBank;
}

bool Boat::isFull() const {
	return Container::getPeople()->size() == 2;
}
