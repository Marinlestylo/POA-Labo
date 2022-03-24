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
    void setNickname(const std::string& name);
protected:
    Ship();
    virtual double getConsomation(double distance, unsigned speed, unsigned weight) const;
private:
    std::string nickname;
};
#endif /* SHIP_HPP */
