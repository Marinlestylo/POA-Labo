/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 17.03.2022
Description     : Fichier principal du programme permettant de tester le bon
                  fonctionnement de la classe Squadron.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#include <iostream>
#include "tieHunter.hpp"
#include "tieInterceptor.hpp"
#include "dreadnought.hpp"
#include "shuttle.hpp"
#include "squadron.hpp"

/**
 * Permet de tester les fonctionnalités liées aux vaisseaux
 */
void testShips() {
    std::cout << std::endl << "--------------------- Tests des Vaisseaux "
                              "---------------------" << std::endl << std::endl;
    std::cout << "Creation et affichage de vaisseaux" << std::endl;
    Shuttle shuttle(20);
    Dreadnought dreadnought(40);
    TieInterceptor tieInterceptor;
    TieHunter tieHunter;
    std::cout << shuttle << std::endl << std::endl <<
              dreadnought << std::endl << std::endl <<
              tieInterceptor << std::endl << std::endl <<
              tieHunter << std::endl << std::endl;
    std::cout << "Changement de nom pour Dreadnought :" << std::endl;
    dreadnought.setNickname("Dreadnought");
    std::cout << dreadnought << std::endl;

    std::cout << "Formule de consommation pour DreadNought avec une cargaison de "
                 "taille 40, la distance et la vitesse sont de 20 :" << std::endl;
    std::cout << dreadnought.getConsumption(20, 20) << std::endl;

    // Les méthodes non constantes ne peuvent pas être appelées sur une instance
    // constantes.
    std::cout << "Tests des ships constants :" << std::endl;
    const Dreadnought constantShip(40);
	 //constantShip.setLoad(466);
	 // impossible d'appeler cette fonction
    std::cout << constantShip << std::endl;

	 std::cout << "Tests des transporters :" << std::endl;
	try {
		Shuttle shut(100);
	} catch (std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
	}
	Dreadnought dread(155);
	try {
		dread.setLoad(100444444);
	} catch (std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
	}
}








/**
 * Permet de tester les fonctionnalités liées aux squadrons
 */
void testSquadron() {

    std::cout << std::endl << "--------------------- Tests des Squadrons "
                              "---------------------" << std::endl << std::endl;

    std::cout << "Creation d'un Squadron" << std::endl;
    Squadron squad1("test1");
    std::cout << squad1 << std::endl;

    std::cout << "Creation d'un Squadron constant" << std::endl;


    // Les méthodes non constantes ne peuvent pas être appelées sur une instance
    // constantes.
    const Squadron squadStat("testsConst");
	 // squadStat.addShipToSquadron()
    std::cout << squadStat << std::endl;


    std::cout << "Creation de vaisseaux" << std::endl;
    Shuttle shuttle(20);
    Dreadnought dreadnought(40);
    TieInterceptor tieInterceptor;
    TieHunter tieHunter;
    std::cout << shuttle << std::endl << std::endl <<
              dreadnought << std::endl << std::endl <<
              tieInterceptor << std::endl << std::endl <<
              tieHunter << std::endl << std::endl;

    std::cout << "Ajout des vaisseaux dans le squadron1" << std::endl;
    squad1.addShipToSquadron(shuttle);
    squad1.addShipToSquadron(dreadnought);

    std::cout << squad1 << std::endl;

    std::cout << "Test du constructeur de copie (squad2)" << std::endl;
    Squadron squad2(squad1);
    std::cout << squad2 << std::endl;

    squad1.addShipToSquadron(tieInterceptor);
    squad1.addShipToSquadron(tieHunter);

    std::cout << "Test de l'operateur d'affectation" << std::endl;
    squad2 = squad1;
    std::cout << "Squad 1" << std::endl << squad1 << std::endl;
    std::cout << "Squad 2" << std::endl << squad2 << std::endl;

	std::cout << "Test de l'operateur d'addition" << std::endl;
	TieHunter add;
	std::cout << "Squad 2 avec add" << std::endl << squad2 + add << std::endl;

	std::cout << "Test de l'operateur de soustraction" << std::endl;
	std::cout << "Squad 2 avec add" << std::endl << (squad2 - shuttle) <<
	std::endl;

    std::cout << "Test de la suppression des vaisseaux (shuttle est enlevé 2X)" <<
              std::endl;
    squad1.removeShipFromSquadron(shuttle);
    squad1.removeShipFromSquadron(shuttle);
    squad1.removeShipFromSquadron(dreadnought);
    squad1.removeShipFromSquadron(tieInterceptor);
    squad1.removeShipFromSquadron(tieHunter);
    std::cout << squad1 << std::endl;



    std::cout << "Choix du chef du squadron1 -> tieHunter" << std::endl;
    squad1.setLeader(tieHunter);
    std::cout << squad1 << std::endl;

	std::cout << "Choix du chef du squadron1 avec un vaisseau qui n'en fait pas "
					 "partie"	<< std::endl;
	TieHunter notMember;
	squad1.setLeader(notMember);

	std::cout << squad1 << std::endl;


    std::cout << "Test de la formule de consommation (avec une distance et une "
                 "vitesse de 100)" << std::endl;
    std::cout << "Consommation de l'escadrille ne contenant qu'un TieHunter : "
              << squad1.getConsumption(100, 100) << std::endl;
    std::cout << "Consommation d'un TieHunter : " << tieHunter.getConsumption(100,
                                                                              100)
              << std::endl;
    std::cout << squad1 << std::endl << std::endl;

    std::cout << "Affichage du vaisseau 0 via la methode get" << std::endl;
    std::cout << squad1.getShip(0) << std::endl << std::endl;

    std::cout << "Affichage d'un vaisseau en dehors des index limites via la "
                 "methode get" << std::endl << std::endl;
    try {
        squad1.getShip(5);
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Consommation d'un squadron avec une distance ou une vitesse "
                 "invalide" << std::endl;
    try {
        squad1.getConsumption(-1, 10);
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        squad1.getConsumption(1, 1000000);
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    TieHunter blackLeader;
    blackLeader.setNickname("Black leader");
    TieHunter blackTwo;
    Shuttle shuttle(23.4); // 23.4 tonnes de marchandises

    Squadron squad("Black Squadron");
    squad += blackLeader;
    squad += blackTwo;
    squad += shuttle;
    squad.setLeader(blackLeader);
    std::cout << squad << std::endl << std::endl;

	 // testShips();
    // testSquadron();

    return EXIT_SUCCESS;
}

/* --------------------------------------------------------------------------------------*/



#ifndef LABO1_SQUADRON_HPP
#define LABO1_SQUADRON_HPP

#include "ship.hpp"

class Squadron;

/**
 * Opérateur de flux de l'escadrille
 * @param os flux d'écriture
 * @param squadron escadrille à écrire
 * @return flux d'écriture
 */
std::ostream &operator<<(std::ostream &os, const Squadron &squadron);

/**
 * Opérateur plus de l'escadrille
 * @param squadron escadrille où ajouter un vaisseau
 * @param ship vaisseau à ajouter
 * @return une copie de l'escadrille avec le vaisseau ajouté
 */
Squadron operator+(const Squadron &squadron, Ship &ship);

/**
 * Opérateur moins de l'escadrille
 * @param squadron escadrille où enlever un vaisseau
 * @param ship vaisseau à enlever
 * @return une copie de l'escadrille avec le vaisseau enlevé
 */
Squadron operator-(const Squadron &squadron, const Ship &ship);

/**
 * Classe permettant de modéliser une escadrille contenant des
 * vaisseaux et potentiellement un chef.
 * @author Alexandre Jaquier
 * @author Jonathan Friedli
 */
class Squadron {
    struct Link {
        Ship *value;
        Link *next;
    };

public:
    /**
     * Constructeur de la classe Squadron
     * @param name nom de l'escadrille
     */
    explicit Squadron(const std::string &name);

    /**
    * Constructeur par copie de la classe Squadron
    * @param other escadrille à copier
    */
    Squadron(const Squadron &other);

    /**
    * Déstructeur de la classe Squadron
    */
    ~Squadron();

    /**
    * Opérateur d'affectation de l'escadrille, copie tous les vaisseaux ainsi que
    * le nom et le chef d'escadrille
    * @param other
    * @return
    */
    Squadron &operator=(const Squadron &other);

    /**
    * Méthode permettant de définir le chef de l'escadrille, si le vaisseau ne fait
    * pas parti des membres de l'escadrille il y est ajouté
    * @param newLeader chef de l'escadrille
    */
    void setLeader(Ship &newLeader);

    /**
     * Méthode permettant de rajouter un vaisseau dans l'escadrille
     * @param ship
     * @return une référence sur l'escadrille
     */
    Squadron &addShipToSquadron(Ship &ship);

    /**
     * Méthode permettant de retirer un vaisseau de l'escadrille
     * @param ship
     * @return une référence sur l'escadrille
     */
    Squadron &removeShipFromSquadron(const Ship &ship);

    /**
     * Méthode permettant de récupérer un vaisseau de l'escadrille
     * @throws out_of_range si le paramètre est en dehors des index de la liste
     * @param index index du vaisseau dans la liste
     * @return une référence constante sur le vaisseau récupéré
     */
    const Ship &getShip(size_t index) const;

    /**
     * Méthode permettant de récupérer différentes informations sur l'escadrille
     * @param speed vitesse de l'escadrille
     * @param weight poids de l'escadrille
     */
    void squadronInfos(unsigned &speed, double &weight) const;

    /**
     * Méthode retournant une nouvelle escadrille contenant les vaisseaux de
     * l'escadrille appelée et enlevant le vaisseau passé en paramètre
     * @param ship vaisseau à enlever de l'escadrille
     * @return une nouvelle escadrille
     */
    Squadron removeShip(const Ship &ship) const;

    /**
     * Méthode retournant une nouvelle escadrille contenant les vaisseaux de
     * l'escadrille appelée et ajoutant le vaisseau passé en paramètre
     * @param ship vaisseau à ajouter à l'escadrille
     * @return une nouvelle escadrille
     */
    Squadron addShip(Ship &ship) const;

    /**
     * Opérateur permettant de rajouter un vaisseau dans l'escadrille
     * @param ship vaisseau à ajouter
     * @return une référence sur l'escadrille
     */
    Squadron &operator+=(Ship &ship);

    /**
     * Opérateur permettant de retirer un vaisseau de l'escadrille
     * @param ship vaisseau à retirer
     * @return une référence sur l'escadrille
     */
    Squadron &operator-=(const Ship &ship);




    /**
     * Méthode permettant de récupérer la consommation de l'escadrille
     * @param distance distance parcourue
     * @param speed vitesse de l'escadrille
     * @return la consommation de l'escadrille
     */
    double getConsumption(double distance, unsigned speed) const;

    /**
     * Opérateur permettant de récupérer un vaisseau de l'escadrille
     * @throws out_of_range si le paramètre est en dehors des index de la liste
     * @param i index du vaisseau dans la liste
     * @return une référence constante sur le vaisseau récupéré
     */
    const Ship &operator[](size_t i) const;

    /**
     * Permet d'afficher les informations d'une escadrille dans un flux
     * @param os flux dans lequel nous écrivons
     * @return une référence sur le flux modifié
     */
    std::ostream &toStream(std::ostream &os) const;

private:
    /**
     * Méthode permettant d'initialiser les paramètres de l'escadrille
     */
    void initVariables(const std::string &newName, Ship *newLeader, Ship *newHead);

    Ship *leader;
    Link *listHead;
    std::string name;
};


#endif //LABO1_SQUADRON_HPP

/* --------------------------------------------------------------------------------------*/

#include "squadron.hpp"
#include <cmath>

using namespace std;

Squadron::Squadron(const string &name) {
    initVariables(name, nullptr, nullptr);
}

Squadron::Squadron(const Squadron &other) {
    initVariables(other.name, other.leader, other.listHead->value);
    Link *toCopy = other.listHead->next;
    while (toCopy != nullptr) {
        addShipToSquadron(*toCopy->value);
        toCopy = toCopy->next;
    }
}

Squadron::~Squadron() {
    Link *tmp = listHead;
    Link *toDelete = listHead;
    while (tmp != nullptr) {
        tmp = tmp->next;
        delete toDelete;
        toDelete = tmp;
    }
}



void Squadron::initVariables(const string &newName, Ship *newLeader, Ship *newHead) {
    this->name = newName;
    this->leader = newLeader;
    this->listHead = newHead == nullptr ? nullptr : new Link{newHead, nullptr};
}

Squadron &Squadron::operator=(const Squadron &other) {
    if (this == &other) {
        return *this;
    }
    Link *toDelete = listHead;
    Link *tmp = toDelete->next;

    while (toDelete != nullptr) {
        delete toDelete;
        toDelete = tmp;
        if (tmp != nullptr) {
            tmp = tmp->next;
        }
    }
    initVariables(other.name, other.leader, other.listHead->value);
    tmp = other.listHead->next;
    while (tmp != nullptr) {
        addShipToSquadron(*tmp->value);
        tmp = tmp->next;
    }
    return *this;
}

void Squadron::setLeader(Ship &newLeader) {
    addShipToSquadron(newLeader);
    this->leader = &newLeader;
}

Squadron Squadron::addShip(Ship &ship) const {
    Squadron newSquadron(*this);
    return newSquadron.addShipToSquadron(ship);;
}

Squadron Squadron::removeShip(const Ship &ship) const {
    Squadron newSquadron(*this);
    return newSquadron.removeShipFromSquadron(ship);
}

Squadron &Squadron::addShipToSquadron(Ship &ship) {
    Link *tmp = listHead;
    if (tmp == nullptr) {
        listHead = new Link{&ship, nullptr};
        return *this;
    }
    while (tmp != nullptr) {
        if (tmp->value == &ship) {
            return *this;
        }
        if (tmp->next == nullptr) {
            break;
        }
        tmp = tmp->next;
    }
    tmp->next = new Link{&ship, nullptr};
    return *this;
}







Squadron &Squadron::removeShipFromSquadron(const Ship &ship) {
    Link *toRemove = listHead;
    Link *tmp = listHead;
    while (toRemove != nullptr) {
        if (toRemove->value == &ship) {
            if (toRemove == listHead) {
                listHead = toRemove->next;
            } else {
                tmp->next = toRemove->next;
            }
            delete toRemove;
            break;
        }
        tmp = toRemove;
        toRemove = toRemove->next;
    }
    return *this;
}

const Ship &Squadron::getShip(size_t index) const {
    Link *tmp = listHead;
    size_t counter = 0;
    while (counter++ != index && tmp->next != nullptr) {
        tmp = tmp->next;
    }
    if (counter == index + 1) {
        return *tmp->value;
    }
    throw out_of_range("Le Squadron ne contient pas de vaisseau a cet index");
}

void Squadron::squadronInfos(unsigned &speed, double &weight) const {
    speed = 0;
    weight = 0;

    Link *tmp = listHead;
    while (tmp != nullptr) {
        if (speed > tmp->value->getMaxSpeed() || speed == 0) {
            speed = tmp->value->getMaxSpeed();
        }
        weight += tmp->value->getWeight();
        tmp = tmp->next;
    }
}

Squadron &Squadron::operator+=(Ship &ship) {
    return addShipToSquadron(ship);
}

Squadron &Squadron::operator-=(const Ship &ship) {
    return removeShipFromSquadron(ship);
}

const Ship &Squadron::operator[](size_t i) const {
    return getShip(i);
}


Squadron operator+(const Squadron &squadron, Ship &ship) {
    return squadron.addShip(ship);
}

Squadron operator-(const Squadron &squadron, const Ship &ship) {
    return squadron.removeShip(ship);
}




double Squadron::getConsumption(double distance, unsigned int speed) const {
    unsigned maxSpeed;
    double totalWeight;
    squadronInfos(maxSpeed, totalWeight);
    if (speed > maxSpeed || distance < 0) {
        throw std::invalid_argument("Ce squadron ne peut pas atteindre une telle "
                                    "vitesse ou une telle distance");
    }

    Link *ship = this->listHead;
    double consumption = 0;

    while (ship != nullptr) {
        consumption += ship->value->getConsumption(distance, speed);
        ship = ship->next;
    }
    return consumption;
}

ostream &operator<<(ostream &os, const Squadron &squadron) {
    return squadron.toStream(os);
}

std::ostream &Squadron::toStream(std::ostream &os) const{
    unsigned maxSpeed;
    double squadronWeight;
    squadronInfos(maxSpeed, squadronWeight);

    os << "Squadron: " << name << endl;
    os << " max speed: " << maxSpeed << " MGLT" << endl;
    os << " total weight: " << squadronWeight << " tons" << endl;

    os << endl << "-- Leader" << endl;
    Squadron::Link *member = listHead;
    if (leader != nullptr)
        os << *leader << endl << endl;

    os << "-- Members" << endl;
    while (member != nullptr) {
        if (member->value != leader)
            os << *member->value << endl << endl;
        member = member->next;
    }
    return os;
}

/* --------------------------------------------------------------------------------------*/


#ifndef SHIP_HPP
#define SHIP_HPP

#include <ostream>
#include "shipCharacteristic.hpp"

class Ship;

/**
 * Surcharge de l'opérateur d'écriture dans un flux afin d'y écrire les informations 
 * d'un vaisseau. Fait appel à la
 * méthode toStream
 * @param os flux dans lequel on écrit
 * @param ship Vaisseaux dont nous allons afficher les informations
 * @return une référence sur l'opérateur de flux
 */
std::ostream &operator<<(std::ostream &os, const Ship &ship);



/**
 * Classe modélisant toutes sorte de vaisseaux spatiaux.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class Ship {

protected :
    /**
     * Constructeur de la classe vaisseau
     * @param characteristic pointeur sur les caractéristique du vaisseau telles
     * que la vitesse maximum ou le modèle
     */
    explicit Ship(ShipCharacteristic *characteristic);

public:
    /**
     * Destructeur de la classe vaisseau
     */
    virtual ~Ship() = default;

    /**
     * Permet d'afficher les informations d'un vaisseau dans un flux
     * @param os flux dans lequel nous écrivons
     * @return une référence sur le flux modifié
     */
    virtual std::ostream &toStream(std::ostream &os) const;

    /**
     * Permet de modifier le nickname du vaisseau
     * @param name nouveau nom
     */
    void setNickname(const std::string &name);

    /**
     * Renvoie le poids du vaisseau en tonne
     * @return le poids en tonne
     */
    virtual double getWeight() const;

    /**
     * Renvoie la vitesse maximale du vaisseau
     * @return la vitesse en MGLT
     */
    unsigned int getMaxSpeed() const;

    /**
     * Calcule la consommation d'un vaisseau compte tenu de sa vitesse, de la distance du trajet 
	 * et de son chargement
     * @throws invalid_argument si la vitesse voulue n'est pas atteignable par le
     * vaisseau ou la distance est négative
     * @param distance Distance parcourue en millions de km
     * @param speed Vitesse à laquelle le vaisseau avance en MGLT
     * @return La consomation en tonne
     */
    double getConsumption(double distance, unsigned speed) const;

private:
    /**
     * Construit un string représentant l'identité du vaisseau sous la forme "[<modèle> #<id>]"
     * @return l'identité du vaisseau
     */
    std::string getIdentity() const;

    unsigned int id;
    std::string nickname;
    const ShipCharacteristic *characteristic;
};
#endif /* SHIP_HPP */

/* --------------------------------------------------------------------------------------*/
#include "ship.hpp"
#include <cmath>
#include <iomanip>

Ship::Ship(ShipCharacteristic *characteristic) :
        characteristic(characteristic) {
    id = characteristic->nextId();
}

std::ostream &operator<<(std::ostream &os, const Ship &ship) {
    return ship.toStream(os);
}

std::ostream &Ship::toStream(std::ostream &os) const {
    return os << (nickname.empty() ? "" : (nickname + " ")) << (getIdentity()) + "\n"
              << "  weight : "
              << std::fixed << std::setprecision(2) << getWeight()
              << " tons\n  max speed : " << characteristic->getMaxSpeed()
              << " MGLT";
}

double Ship::getConsumption(double distance, unsigned speed) const {
    if (speed > characteristic->getMaxSpeed() || distance < 0) {
        throw std::invalid_argument("La vitesse ou la distance n'est pas "
                                    "atteignable");
    }
    return cbrt(getWeight()) / 2 * log10(getWeight() * speed) * log10(distance + 1);
}

void Ship::setNickname(const std::string &name) {
    nickname = name;
}

std::string Ship::getIdentity() const {
    return "[" + characteristic->getModele() + " #" + std::to_string
            (id) + "]";
}

double Ship::getWeight() const {
    return characteristic->getWeight();
}

unsigned int Ship::getMaxSpeed() const {
    return characteristic->getMaxSpeed();
}

/* --------------------------------------------------------------------------------------*/

#ifndef LABO1_TRANSPORTER_HPP
#define LABO1_TRANSPORTER_HPP

#include "ship.hpp"
#include "transporterCharacteristic.hpp"

/**
 * Déclaration de la classe Transporter héritant de Ship et modélisant des vaisseaux transportant
 * des cargaisons.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class Transporter : public Ship {
protected:





    /**
     * Constructeur de la classe Transporter
     * @param currentLoad poids de la cargaison en tonne
     * @param characteristic Pointeur sur les caractéristique d'un vaisseau pouvant
     * transporter une cargaison
     */
    Transporter(double currentLoad, TransporterCharacteristic *characteristic);

public:
    /**
     * Renvoie le poids de la cargaison courrante en tonne
     * @return le poids de la cargaison en tonne
     */
    double getLoad() const;

    /**
     * Permet de mettre à jours le poids de la cargaison
     * @param load nouveau poids en tonne
     */
    void setLoad(double load);

    /**
     * Redéfinition de la fonction toStream. Elle affiche les informations du vaisseau dans un flux
     * @param os flux d'écriture dans lequel on écrit
     * @return Une référence sur le flux modifié
     */
    std::ostream &toStream(std::ostream &os) const override;

    /**
	 * Renvoie le poids du vaisseau + celui de sa cargaison en tonne
	 * @return le poids total en tonne
	 */
    double getWeight() const override;

private:
    double currentLoad;
    TransporterCharacteristic *characteristic;
};


#endif //LABO1_TRANSPORTER_HPP

/* --------------------------------------------------------------------------------------*/


#include "transporter.hpp"
#include <iomanip>
#include <iostream>

Transporter::Transporter(
        double currentLoad, TransporterCharacteristic *characteristic) :
        Ship(characteristic) {
    this->characteristic = characteristic;
    setLoad(currentLoad);
}

double Transporter::getLoad() const {
    return currentLoad;
}

void Transporter::setLoad(double load) {
    if (load > this->characteristic->getMaxLoad() || load < 0) {
        throw std::invalid_argument("Vous tentez de mettre une cargaison trop lourde"
                                    " dans ce vaisseau !");
    }
    currentLoad = load;
}


std::ostream &Transporter::toStream(std::ostream &os) const {
    return Ship::toStream(os) << std::endl <<"  cargo : " << std::setprecision(1)
                              << currentLoad << " tons (max : "
                              << characteristic->getMaxLoad() << ")";
}

double Transporter::getWeight() const {
    return characteristic->getWeight() + currentLoad;
}

/* --------------------------------------------------------------------------------------*/

#ifndef LABO1_TIEHUNTER_HPP
#define LABO1_TIEHUNTER_HPP

#include "ship.hpp"

/**
 * Déclaration de la classe TieHunter héritant de Vaisseau.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class TieHunter : public Ship {
public:

    /**
     * Constructeur de la classe TieHunter
     */
    TieHunter();

private:
    static ShipCharacteristic characteristic;
};


#endif //LABO1_TIEHUNTER_HPP

/* --------------------------------------------------------------------------------------*/

#include "tieHunter.hpp"

ShipCharacteristic TieHunter::characteristic(
        "TIE/LN", 100, 6
);

TieHunter::TieHunter() : Ship(&characteristic) {}

/* --------------------------------------------------------------------------------------*/

#ifndef LABO1_TIEINTERCEPTOR_HPP
#define LABO1_TIEINTERCEPTOR_HPP

#include "ship.hpp"

/**
 * Déclaration de la classe TieInterceptor héritant de Vaisseau.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class TieInterceptor : public Ship {
public:
    /**
     * Constructeur de la classe TieInterceptor
     */
    TieInterceptor();
private:
    static ShipCharacteristic characteristic;
};
#endif //LABO1_TIEINTERCEPTOR_HPP

/* --------------------------------------------------------------------------------------*/

#include "tieInterceptor.hpp"

ShipCharacteristic TieInterceptor::characteristic(
        "TIE/IN", 110, 5
);

TieInterceptor::TieInterceptor() : Ship(&characteristic) {}

/* --------------------------------------------------------------------------------------*/

#ifndef LABO1_DREADNOUGHT_HPP
#define LABO1_DREADNOUGHT_HPP

#include "transporter.hpp"


/**
 * Déclaration de la classe Dreadnought héritant de Transporter.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class Dreadnought : public Transporter {
public:

    /**
     * Constructeur de la classe Dreadnought
     * @param load poids de la cargaison en tonne
     */
    explicit Dreadnought(double load);

private:
    static TransporterCharacteristic characteristic;
};


#endif //LABO1_DREADNOUGHT_HPP

/* --------------------------------------------------------------------------------------*/

#include "dreadnought.hpp"

TransporterCharacteristic Dreadnought::characteristic(
        "Super-class Star Destroyer", 40, 9000000000, 250000
);

Dreadnought::Dreadnought(double load) : Transporter(
        load, &characteristic
) {}

/* --------------------------------------------------------------------------------------*/

#ifndef LABO1_SHUTTLE_HPP
#define LABO1_SHUTTLE_HPP

#include "transporter.hpp"
#include "transporterCharacteristic.hpp"

/**
 * Déclaration de la classe shuttle héritant de Transporter.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class Shuttle : public Transporter {
public:


    /**
     * Constructeur de la classe Shuttle
     * @param load poids de la cargaison en tonne
     */
    explicit Shuttle(double load);

private:
    static TransporterCharacteristic characteristic;
};


#endif //LABO1_SHUTTLE_HPP

/* --------------------------------------------------------------------------------------*/

#include "shuttle.hpp"

TransporterCharacteristic Shuttle::characteristic(
        "Lambda-class shuttle", 54, 360, 80
);

Shuttle::Shuttle(double load) : Transporter(
        load, &characteristic
) {}

/* --------------------------------------------------------------------------------------*/

#ifndef LABO1_SHIPCHARACTERISTIC_HPP
#define LABO1_SHIPCHARACTERISTIC_HPP


#include <string>

/**
 * Classe modélisant les différentes caractéristiques d'un vaisseau spatial telle
 * que sa vitesse maximale, son modèle et son poids.
 * @authors Alexandre Jaquier et Jonathan Friedli
 * @date 17.03.2022
 */
class ShipCharacteristic {
public:
    /**
     * Constructeur de la classe ShipCharacteristic
     * @param modele modele du vaisseau
     * @param maxSpeed Vitesse maximale en MGLT
     * @param weight poids du vaisseau en tonne
     */
    ShipCharacteristic(const std::string &modele, unsigned maxSpeed, double weight);

    /**
     * Destructeur de la classe ShipCharacteristic
     */
    virtual ~ShipCharacteristic() = default;

    /**
     * Renvoie le modèle du vaisseau
     * @return le modèle
     */
    const std::string &getModele() const;

    /**
     * Renvoie la vitesse max du vaisseau en MGLT
     * @return la vitesse max en MGLT
     */
    unsigned int getMaxSpeed() const;




    /**
     * Renvoie le poids du vaisseau en tonne
     * @return le poids en tonne
     */
    double getWeight() const;



    /**
     * Permet de générer un id dépendant du type du vaisseau
     * @return le prochain id utilisable
     */
    unsigned int nextId();


private:
    const std::string modele;
    const unsigned maxSpeed;
    const double weight;
    unsigned int counter;
};


#endif //LABO1_SHIPCHARACTERISTIC_HPP


/* --------------------------------------------------------------------------------------*/

#include "shipCharacteristic.hpp"

ShipCharacteristic::ShipCharacteristic(const std::string &modele, unsigned maxSpeed,
                                       double weight) : modele(modele), maxSpeed
        (maxSpeed), weight(weight), counter(1) {}

const std::string &ShipCharacteristic::getModele() const {
    return modele;
}

unsigned int ShipCharacteristic::getMaxSpeed() const {
    return maxSpeed;
}

double ShipCharacteristic::getWeight() const {
    return weight;
}

unsigned int ShipCharacteristic::nextId() {
    return counter++;
}

/* --------------------------------------------------------------------------------------*/


#ifndef LABO1_TRANSPORTERCHARACTERISTIC_HPP
#define LABO1_TRANSPORTERCHARACTERISTIC_HPP


#include "shipCharacteristic.hpp"

/**
 * Classe héritant de shipCharacteristic permettant de modéliser le poids maximal de
 * la cargaison d'un vaisseau
 */
class TransporterCharacteristic : public ShipCharacteristic {
public:




	/**
	 * Constructeur de la classe TransporterCharacteristic
	 * @param modele Modèle du vaisseau
	 * @param maxSpeed Vitesse max du vaisseau en MGLT
	 * @param weight Poids du vaisseau en tonne
	 * @param maxLoad Poids maximal de la cargaison en tonne
	 */
	TransporterCharacteristic(const std::string& modele, unsigned maxSpeed,
									  double weight, double maxLoad);



	/**
	 * Renvoie le poids maximal de la cargaison en tonne
	 * @return le poids max en tonne
	 */
	double getMaxLoad() const;

private:
	double maxLoad;
};


#endif //LABO1_TRANSPORTERCHARACTERISTIC_HPP


/* --------------------------------------------------------------------------------------*/


#include "transporterCharacteristic.hpp"

TransporterCharacteristic::TransporterCharacteristic(
        const std::string &modele, unsigned maxSpeed, double weight, double maxLoad)
        : ShipCharacteristic(modele, maxSpeed, weight), maxLoad(maxLoad) {}

double TransporterCharacteristic::getMaxLoad() const {
    return maxLoad;
}
