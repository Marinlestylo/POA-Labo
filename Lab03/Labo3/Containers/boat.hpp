#ifndef LABO3_BOAT_HPP
#define LABO3_BOAT_HPP

#include "bank.hpp"
#include "container.hpp"

class Boat : public Container {
public:
    explicit Boat(Bank &current);

    bool moveBoat(Bank &bank);

    bool isDockedOnthisBank(Bank &bank) const;

    std::ostream &toStream(std::ostream &os) const override;

    bool isOnBank(const Person& person) const;

    bool isFull() const override;

private:
    Bank *currentBank;
    static const std::string RIVER;
    static const int MAX_CAPACITY = 2;
};


#endif //LABO3_BOAT_HPP
