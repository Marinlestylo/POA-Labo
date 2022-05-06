//
// Created by Jonathan on 14.04.2022.
//

#ifndef LABO3_BOAT_HPP
#define LABO3_BOAT_HPP

#include "bank.hpp"
#include "container.hpp"

class Boat : public Container {
public:
    explicit Boat(Bank* current);

    void moveBoat(Bank *bank);

	 bool isDockedOnthisBank(Bank* bank) const;

    /**
     * method that print the boat on the screen and all the people on the boat
     */
	 void showContainer() const override;

	 Bank* getBank() const;

	 bool isFull() const;
private:
    Bank* currentBank;
	 static const std::string RIVER;
};


#endif //LABO3_BOAT_HPP
