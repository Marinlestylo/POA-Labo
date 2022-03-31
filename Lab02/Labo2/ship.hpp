#ifndef SHIP_HPP
#define SHIP_HPP
#include <ostream>
class Ship;
std::ostream& operator << (std::ostream& os, const Ship& ship);
class Ship
{
public:
    virtual ~Ship();
    virtual std::ostream& toStream(std::ostream& os) const;
    //virtual unsigned maxSpeed() const = 0;
    void setNickname(const std::string& name);
    virtual double getWeight() const = 0;
    virtual const std::string &getModele() const = 0;
    virtual unsigned int getSpeed() const = 0;

    Ship();
protected:

    virtual double getConsomation(double distance, unsigned speed) const;
private:
    std::string nickname;
};
#endif /* SHIP_HPP */
