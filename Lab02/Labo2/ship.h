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
private:
    /* à compléter */
};
#endif /* SHIP_HPP */
