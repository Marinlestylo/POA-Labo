//
// Created by Jonathan on 14.04.2022.
//

#include "boat.hpp"

Boat::Boat(Bank *bank) : Container("Bateau", std::list<Person *>()), bank(bank) {

}
