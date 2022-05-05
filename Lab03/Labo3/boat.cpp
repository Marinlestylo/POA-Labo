//
// Created by Jonathan on 14.04.2022.
//

#include <iostream>
#include "boat.hpp"

Boat::Boat(Bank *bank) : Container("Bateau", std::list<Person *>()), bank(bank) {

}

void Boat::showContainer() const {
	std::cout << Container::getName() << " : " << "< ";
	Container::showContainer();
	std::cout << " >";
}
