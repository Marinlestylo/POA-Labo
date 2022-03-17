#ifndef SHIP_HPP
#define SHIP_HPP
#include <ostream>
class Ship;
std::ostream& operator << (std::ostream& os, const Ship& ship);
class Ship
{
public:
    virtual ~Ship();
    /* à compléter */
    virtual std::ostream& toStream(std::ostream& os) const;
    unsigned maxSpeed() const;

protected:
    Ship(const std::string& modele, unsigned weight, unsigned speed);
private:
    std::string nickname, modele;
    unsigned weigth, speed;
};
#endif /* SHIP_HPP */
