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
    virtual double getConsomation(double distance, unsigned speed) const;
    void setNickname(const std::string& name);

    static const std::string &getModele();

    static void setModele(const std::string &modele);

    static unsigned int getWeight();

    static void setWeight(unsigned int weight);

    static unsigned int getSpeed();

    static void setSpeed(unsigned int speed);

protected:
    Ship(const std::string& modele, unsigned weight, unsigned speed);
private:
    std::string nickname;
    static std::string modele;
    static unsigned weight, speed;
};
#endif /* SHIP_HPP */
