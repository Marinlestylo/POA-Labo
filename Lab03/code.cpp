#include "controller.hpp"

int main() {
    Controller game;
    game.startGame();
}


/* --------------------------------------------------------------------- */

#ifndef LABO3_CONTROLLER_HPP
#define LABO3_CONTROLLER_HPP

#include <string>
#include <list>
#include "Containers/container.hpp"
#include "Containers/bank.hpp"
#include "Characters/person.hpp"
#include "Characters/boy.hpp"
#include "Characters/girl.hpp"
#include "Characters/dependentPerson.hpp"
#include "Characters/driver.hpp"
#include "Characters/thief.hpp"
#include "Containers/boat.hpp"

/**
 * Classe représentant le controller du jeu
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Controller {
public:
    /**
     * Constructeur par défaut de la classe Controller
     */
    Controller();

    /**
     * Opérateur d'affectation de la classe Controller
     */
    void operator=(const Controller&) = delete;

	 /**
	  * Impossibilité d'utiliser le constructeur de copie
	  * @param other
	  */
	 Controller(const Controller& other) = delete;

    /**
     * destructeur de la classe Controller
     */
    ~Controller();

    /**
     * Méthode permettant d'afficher un message d'erreur
     * @param errorMsg le message d'erreur
     */
    static void showError(const std::string &errorMsg);

    /**
     * Méthode permettant de gérer le début du jeu
     */
    void startGame();
private:

    /**
     * Méthode permettant de lancer la boucle de jeu
     */
    void nextTurn();

    /**
     * Crée le bateau, les deux rives ainsi que tous les personnages du jeu.
     */
    void initVariables();

    /**
     * Méthode finissant un tour de jeu
     */
    void endTurn();

    /**
     * Métode permettant d'embarquer un personnage sur le bateau
     * @param p le personnage à embarquer
     */
    void embark(const Person *p);

    /**
     * Méthode permettant de débarquer un personnage du bateau
     * @param p le personnage à débarquer
     */
    void disembark(const Person *p);

    /**
     * Méthode permettant de déplacer le bateau de rive
     */
    void moveBoat();

    /**
    * Méthode permettant d'afficher l'état du jeu
    */
    void display() const;

    /**
     * Méthode permettant de parser les commandes du joueur
     * @param input la commande entrée par le joueur
     */
    void parseInput(const std::string& input);

    /**
     * Permet de remettre le jeu dans son état initiale afin de le recommencer
     */
    void reset();

    /**
     * Méthode permettant de récupérer l'input du joueur
     * @return input du joueur
     */
    void userInput();

    /**
    * Méthode permettant d'afficher le menu
    */
    static void showMenu();

    /**
     * Méthode permettant d'afficher une ligne du menu
     * @param command nom de la commande
     * @param info description de la commande
     */
    static void printMenuLine(char command, const std::string &info, const
    std::string &argument = "");

    /**
     * Méthode permettant de convertir un string en personne
     * @param s le string à convertir
     * @return le personnage correspondant au string
     */
    const Person *compareStringToPerson(const std::string &s) const;

    /**
     * Méthode permettant de changer un personnage de container
     * @param p personnage à changer de place
     * @param toAdd lieu ou ajouter le personnage
     * @param addFrom lieu ou enlever le personnage
     */
    void changeLocation(const Person &p, Container &toAdd, Container &addFrom);

    /**
     * Méthode permettant de savoir si le jeu est terminé
     * @return vrai si le jeu est terminé
     */
    bool endOfGame() const;


    int turn;
    bool gameRunning;
    Bank *leftBank, *rightBank;
    Boat *boat;
    std::list<const Person *> people;
    static const std::string ERROR_MESSAGE, SEPARATOR;
    static const char DISPLAY = 'p', EMBARK = 'e', DISEMBARK = 'd', MOVE = 'm' ,
    RESET ='r',EXIT = 'q', HELP = 'h';
};


#endif //LABO3_CONTROLLER_HPP

/* --------------------------------------------------------------------- */
#include "controller.hpp"
#include <iostream>
#include <iomanip>

const std::string Controller::ERROR_MESSAGE = "Input invalide ! (Tapez \"h\" pour "
                                              "obtenir de l'aide) : ";
const std::string Controller::SEPARATOR =
        "------------------------------------------------------------------------------";

Controller::Controller() {
    initVariables();
}

Controller::~Controller() {
    delete boat;
    delete leftBank;
    delete rightBank;
    for (const Person *p: people) {
        delete p;
    }
}

void Controller::initVariables() {
    Driver *mother = new Driver("mere");
    Driver *father = new Driver("pere");
    Boy *paul = new Boy("paul", *father, *mother);
    Boy *pierre = new Boy("pierre", *father, *mother);
    Girl *julie = new Girl("julie", *mother, *father);
    Girl *jeanne = new Girl("jeanne", *mother, *father);
    Driver *policeman = new Driver("policier");
    Thief *thief = new Thief("voleur", *policeman);
    this->people = {mother, father, paul, pierre, julie, jeanne, policeman, thief};
    turn = 0;
    leftBank = new Bank("Gauche");
    rightBank = new Bank("Droite");
    boat = new Boat(*leftBank);
    leftBank->addAll(people);
    gameRunning = true;
}
void Controller::startGame(){
    showMenu();
    display();
    nextTurn();
}

void Controller::showMenu(){
    std::cout << std::endl;
    printMenuLine(DISPLAY, "afficher");
    printMenuLine(EMBARK, "embarquer", " <nom>");
    printMenuLine(DISEMBARK, "debarquer", " <nom>");
    printMenuLine(MOVE, "deplacer bateau");
    printMenuLine(RESET, "reinitialiser");
    printMenuLine(EXIT, "quitter");
    printMenuLine(HELP, "menu");
}

void Controller::nextTurn() {
    while (gameRunning) {
        userInput();
    }
}

void Controller::parseInput(const std::string &input){
    char command;
    const Person *person = nullptr;
    if (input.empty()) {
        showError(ERROR_MESSAGE);
        return;
    }
    if (input.size() > 1 && input[1] == ' ') {
        person = compareStringToPerson(input.substr(2));
    }
    command = input[0];
    switch (command) {
        case DISPLAY:
            display();
            break;
        case EMBARK:
            embark(person);
            break;
        case DISEMBARK:
            disembark(person);
            break;
        case MOVE:
            moveBoat();
            break;
        case RESET:
            reset();
            break;
        case EXIT:
            gameRunning = false;
            break;
        case HELP:
            showMenu();
            break;
        default :
            showError(ERROR_MESSAGE);
    }
}

void Controller::endTurn() {
    ++turn;
    display();
}




void Controller::display() const {
    std::cout << std::endl << SEPARATOR << std::endl;
    leftBank->toStream(std::cout);
    std::cout << std::endl;
    boat->toStream(std::cout);
    std::cout << std::endl;
    rightBank->toStream(std::cout);
    std::cout << std::endl << SEPARATOR << std::endl;
}

void Controller::reset() {
    rightBank->emptyContainer();
    leftBank->emptyContainer();
    boat->emptyContainer();
    for (const Person *p: people) {
        leftBank->addPerson(*p);
    }
    boat->moveBoat(*leftBank);
    turn = 0;
}

void Controller::userInput(){
    std::string input;
    std::cout << turn << ">";
    getline(std::cin, input);
    parseInput(input);
}

void Controller::printMenuLine(char command, const std::string &info, const
std::string &argument) {
    std::cout << command << " " << std::setw(8) << std::left << argument <<
              ": " << info << " " << argument << std::endl;
}

const Person *Controller::compareStringToPerson(const std::string &s) const {
    for (const Person *p: people) {
        if (p->getName() == s) {
            return p;
        }
    }
    return nullptr;
}

void Controller::embark(const Person *p) {
    if (boat->isFull() || !p) {
        showError("Error: Bateau est plein ou la personne n'a pas ete trouvee");
    } else if (boat->isOnBank(*p)) {
        Bank *bank = boat->isDockedOnthisBank(*leftBank) ? leftBank : rightBank;
        changeLocation(*p, *boat, *bank);
    } else {
        showError("Error: La personne n'est pas sur la rive");
    }
}

void Controller::disembark(const Person *p) {
    if (boat->isEmpty()) {
        showError("Error: Le bateau est deja vide");
    } else if (boat->isMember(*p)) {
        Bank *bank = boat->isDockedOnthisBank(*leftBank) ? leftBank : rightBank;
        changeLocation(*p, *bank, *boat);
    } else {
        showError("Error: Personne n'est pas dans le bateau");
    }
    endOfGame();
}




void Controller::changeLocation(const Person &p, Container &toAdd, Container
&toRemove) {
    toAdd.addPerson(p);
    toRemove.removePerson(p);
    if (!(toAdd.isContainerSafe() && toRemove.isContainerSafe())) {
        toAdd.removePerson(p);
        toRemove.addPerson(p);
    } else {
        endTurn();
    }
}

bool Controller::endOfGame() const {
    if (boat->isEmpty() && leftBank->isEmpty()) {
        std::cout << "Vous avez gagne !" << std::endl;
        return true;
    }
    return false;
}

void Controller::showError(const std::string &errorMsg) {
    std::cout << "### " << errorMsg << std::endl;
}

void Controller::moveBoat() {
    Bank* bank = boat->isDockedOnthisBank(*leftBank) ? rightBank : leftBank;
    if(boat->moveBoat(*bank)){
        endTurn();
    } else {
        showError("Il n'y a pas de conducteur dans le bateau");
    }
}

/* --------------------------------------------------------------------- */

#ifndef LABO3_CONTAINER_HPP
#define LABO3_CONTAINER_HPP

#include <string>
#include <algorithm>
#include <list>

class Person;

/**
 * Classe représentant un conteneur
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Container {
protected:
    /**
    * Constructeur de la classe Container
    * @param name Nom du conteneur
    */
    explicit Container(const std::string &name);

public:
    /**
     * Destructeur de la classe Container
     */
    virtual ~Container() = 0;

    /**
     * Méthode permettant de récupérer le container sous forme affichable
     * @param os opérateur de flux
     * @return le container sous forme affichable
     */
    virtual std::ostream &toStream(std::ostream &os) const;

    /**
     * Méthode permettant de récupérer le nom des personnes du conteneur
     * @return le nom des personnes du conteneur
     */
    std::string getPeopleNames() const;

    /**
     * Méthode permettant de récupérer le nom du conteneur
     * @return le nom du conteneur
     */
    std::string getName() const;

    /**
     * Méthode permettant de récupérer la taille
     * @return la taille
     */
    unsigned size() const;

    /**
     * Méthode permettant de vider le container
     */
    void emptyContainer();

    /**
     * Ajoute un personnage au container
     * @throw std::runtime_error si le container est plein
     * @param p personnage à ajouter
     */
    void addPerson(const Person &p);

    /**
     * Ajoute plusieurs personnages au container
     * @throw std::runtime_error si le container est plein
     * @param people liste de personnages à ajouter
     */
    void addAll(const std::list<const Person *> &people);

    /**
     * Enlève un personne du container
     * @throw std::runtime_error si le container est vide
     * @param p personnage à enlever
     */
    void removePerson(const Person &p);

    /**
     * Méthode permettant de savoir si le container est vide
     * @return true si le container est vide, false sinon
     */
    bool isEmpty() const;

    /**
     * Méthode permettant de savoir si le container est plein
     * @return true si le container est plein, false sinon
     */
    virtual bool isFull() const;

    /**
     * Méthode permettant de savoir si un personnage est dans le container
     * @param p personnage à rechercher
     * @return true si le personnage est dans le container, false sinon
     */
    bool isMember(const Person &p) const;






    /**
     * Méthode permettant de savoir si les personnes dans le container sont toutes
     * en sécurité
     * @return true si les personnes sont en sécurité, false sinon
     */
    bool isContainerSafe() const;

    /**
     * Méthode retournant un itérateur constant sur le premier élément de la liste
     * de personnes se trouvant dans le container
     * @return un itérateur constant sur le premier élément de la liste
     */
    std::list<const Person *>::const_iterator begin() const;

    /**
     * Méthode retournant un itérateur constant sur le dernier élément de la liste
     * de personnes se trouvant dans le container
     * @return un itérateur constant sur le dernier élément de la liste
     */
    std::list<const Person *>::const_iterator end() const;

private:
    const std::string name;
    std::list<const Person *> people;
};


#endif //LABO3_CONTAINER_HPP

/* --------------------------------------------------------------------- */

#include <iostream>
#include <sstream>
#include "container.hpp"
#include "../controller.hpp"

Container::Container(const std::string &name) : name(name) {}

Container::~Container() = default;

std::ostream &Container::toStream(std::ostream &os) const {
    return os << getName() << " : " << getPeopleNames() << " ";
}

std::string Container::getPeopleNames() const {
    std::stringstream ss;
    for (auto &person: people) {
        ss << person->getName() << " ";
    }
    return ss.str();
}

std::string Container::getName() const {
    return name;
}

void Container::emptyContainer() {
    people.clear();
}

void Container::addPerson(const Person &p) {
    if (isFull()) {
        throw std::runtime_error("le container est plein");
    }
    people.push_back(&p);
}



void Container::removePerson(const Person &p) {
    if (people.empty()) {
        throw new std::runtime_error("Le container est vide");
    }
    people.remove(&p);
}

bool Container::isMember(const Person &p) const {
    return std::find(people.begin(), people.end(), &p) != people.end();
}

bool Container::isContainerSafe() const {
    for (const Person *p: people) {
        if (!p->isSafe(*this)) {
            Controller::showError(p->getErrorMessage());
            return false;
        }
    }
    return true;
}

bool Container::isEmpty() const {
    return people.empty();
}

bool Container::isFull() const {
    return false;
}

std::list<const Person *>::const_iterator Container::begin() const {
    return people.cbegin();
}

std::list<const Person *>::const_iterator Container::end() const {
    return people.cend();
}

unsigned Container::size() const {
    return people.size();
}

void Container::addAll(const std::list<const Person *> &peopleToAdd) {
    for (const Person *p: peopleToAdd) {
        if (isFull())
            throw std::runtime_error("le container est plein");
        this->people.push_back(p);
    }
}
/* --------------------------------------------------------------------- */
#ifndef LABO3_BANK_HPP
#define LABO3_BANK_HPP

#include "container.hpp"

/**
 * Classe représentant une rive de la rivière
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Bank : public Container {
public:
    /**
     * Constructeur de la classe Bank
     * @param name nom de la rive
     * @param people personne se trouvant sur la rive
     */
    explicit Bank(const std::string &name);
};
#endif //LABO3_BANK_HPP

/* --------------------------------------------------------------------- */

#include "bank.hpp"

Bank::Bank(const std::string &name) : Container(name) {}

/* --------------------------------------------------------------------- */

#ifndef LABO3_BOAT_HPP
#define LABO3_BOAT_HPP

#include "bank.hpp"
#include "container.hpp"

/**
 * Classe représentant un bateau
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Boat : public Container {
public:
    /**
     * Constructeur de la classe Boat
     * @param current rive sur laquelle le bateau se trouve
     */
    explicit Boat(const Bank &current);

    /**
     * Méthode permettant de déplacer le bateau sur une autre rive
     * @param bank La nouvelle rive
     * @return true si le déplacement a réussi, false sinon
     */
    bool moveBoat(const Bank &bank);

    /**
     * Méthode permettant de savoir sur quelle rive le bateau se trouve
     * @param bank rive à checker
     * @return true si le bateau se trouve sur la rive, false sinon
     */
    bool isDockedOnthisBank(const Bank &bank) const;

    /**
     * Méthode permettant de récupérer le bateau sous forme affichable
     * @param os opérateur de sortie
     * @return le bateau sous forme affichable
     */
    std::ostream &toStream(std::ostream &os) const override;

    /**
     * Méthode permettant de savoir si une personne est dans le bateau
     * @param person Personne à rechercher
     * @return true si la personne est dans le bateau, false sinon
     */
    bool isOnBank(const Person& person) const;

    /**
     * Méthode permettant de savoir si le bateau est rempli
     * @return true si le bateau est rempli, false sinon
     */
    bool isFull() const override;

private:
    const Bank *currentBank;
    static const std::string RIVER;
    static const int MAX_CAPACITY = 2;
};

#endif //LABO3_BOAT_HPP

/* --------------------------------------------------------------------- */

#include <iostream>
#include "boat.hpp"
#include "../controller.hpp"

const std::string Boat::RIVER =
        "==============================================================================";

Boat::Boat(const Bank &current) : Container("Bateau"), currentBank(&current) {}


std::ostream &Boat::toStream(std::ostream &os) const {
    if (currentBank->getName() == "Droite")
        os << std::endl << RIVER << std::endl;

    os << Container::getName() << " : " << "< " << Container::getPeopleNames() <<
       ">";
    if (currentBank->getName() == "Gauche")
        std::cout << std::endl << RIVER << std::endl;
    return os;
}

bool Boat::moveBoat(const Bank &bank) {
    bool hasDriver = false;
    auto end = Container::end();
    for(auto it = Container::begin(); it != end; ++it) {
        if ((*it)->canDrive()) {
            hasDriver = true;
            break;
        }
    }
    if (!hasDriver) {
        return false;
    }
    currentBank = &bank;
    return true;
}

bool Boat::isDockedOnthisBank(const Bank &bank) const {
    return &bank == currentBank;
}

bool Boat::isFull() const {
    return Container::size() >= MAX_CAPACITY;
}

bool Boat::isOnBank(const Person &person) const {
    return currentBank->isMember(person);
}

/* --------------------------------------------------------------------- */

#ifndef LABO3_PERSON_HPP
#define LABO3_PERSON_HPP

#include <list>
#include <string>

class Container;
/**
 * Classe représentant une personne
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
 
 
 
class Person {
protected:
    /**
    * Constructeur de la classe Person
    * @param name nom de la personne
    */
    explicit Person(const std::string& name);

public:
    /**
     * Destructeur de la classe Person
     */
    virtual ~Person() = 0;

    /**
     * Méthode permettant de savoir si la personne peut conduire
     * @return true si la personne peut conduire, false sinon
     */
    virtual bool canDrive() const;

    /**
     * Méthode permettant de connaitre le nom de la personne
     * @return le nom de la personne
     */
    std::string getName() const;

    /**
     * Méthode permettant de savoir si la personne est en sécurité dans un lieu
     * @param people liste des personnes présentes dans le lieu
     * @return true si la personne est en sécurité, false sinon
     */
    virtual bool isSafe(const Container& container) const;

    /**
     * Méthode permettant d'avoir un message d'erreur lié à la personne
     * @return un message d'erreur
     */
    virtual std::string getErrorMessage() const;

private:
    const std::string name;
    static const std::string ERROR_MESSAGE;
};


#endif //LABO3_PERSON_HPP

/* --------------------------------------------------------------------- */
#include "person.hpp"

#include "../Containers/container.hpp"

const std::string Person::ERROR_MESSAGE = "aucune erreur possible";

Person::~Person() = default;

Person::Person(const std::string &name) : name(name) {}

bool Person::canDrive() const {
    return false;
}

std::string Person::getName() const {
    return name;
}

bool Person::isSafe(const Container &container) const {
    return true;
}

std::string Person::getErrorMessage() const {
    return ERROR_MESSAGE;
}


/* --------------------------------------------------------------------- */

#ifndef LABO3_DRIVER_HPP
#define LABO3_DRIVER_HPP

#include "person.hpp"

/**
 * Classe représentant les conducteurs
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Driver : public Person {
public:
    /**
     * Constructeur de la classe Driver
     * @param name nom du conducteur
     */
    explicit Driver(const std::string &name);

    /**
     * Méthode permettant de savoir si la personne peut conduire
     * @return true si la personne peut conduire, false sinon
     */
    bool canDrive() const override;
};


#endif //LABO3_DRIVER_HPP


/* --------------------------------------------------------------------- */

#include "driver.hpp"

Driver::Driver(const std::string &name) : Person(name) {}

bool Driver::canDrive() const {
    return true;
}


/* --------------------------------------------------------------------- */

#ifndef LABO3_THIEF_HPP
#define LABO3_THIEF_HPP


#include "person.hpp"

/**
 * Classe représentant un voleur
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Thief : public Person {
public:
    /**
     * Constructeur de la classe Thief
     * @param name nom du voleur
     * @param goodWith Personne avec qui le voleur peut rester
     */
    Thief(const std::string &name, const Person &goodWith);

    /**
     * Méthode permettant de savoir si la personne est en sécurité dans un lieu
     * @param people liste des personnes présentes dans le lieu
     * @return true si la personne est en sécurité, false sinon
     */
    bool isSafe(const Container &container) const override;

    /**
    * Méthode permettant d'avoir un message d'erreur lié à la personne
    * @return un message d'erreur
    */
    std::string getErrorMessage() const override;

private:
    static const std::string ERROR_MESSAGE;
    const Person *dependsOn;
};


#endif //LABO3_THIEF_HPP


/* --------------------------------------------------------------------- */

#include "thief.hpp"
#include "../Containers/container.hpp"

const std::string Thief::ERROR_MESSAGE = "voleur sans policier";

Thief::Thief(const std::string &name, const Person &goodWith) : Person(name) {
    this->dependsOn = &goodWith;
}

bool Thief::isSafe(const Container &container) const {
    if (container.size() == 1) {
        return true;
    }
    for (auto it = container.begin(); it != container.end(); ++it) {
        if (*it == this->dependsOn) {
            return true;
        }
    }
    return false;
}

std::string Thief::getErrorMessage() const {
    return ERROR_MESSAGE;
}


/* --------------------------------------------------------------------- */

#ifndef LABO3_DEPENDENTPERSON_HPP
#define LABO3_DEPENDENTPERSON_HPP

#include "person.hpp"
#include <algorithm>

/**
 * Classe représentant une personne dépendante de deux autre
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
 
 
 
 
 
class DependentPerson : public Person {
protected:
    /**
    * Constructeur de la classe DependentPerson
    * @param name nom de la personne
    * @param dependsOn personne de qui la personne dépend
    * @param badWith personne avec laquelle elle ne peut pas rester
    */
    DependentPerson(const std::string &name, const Person &dependsOn, const Person &
    badWith);

public:
    /**
     * Destructeur de la classe DependentPerson
     */
    ~DependentPerson() = 0;

    /**
     * Méthode permettant de savoir si la personne est en sécurité dans un lieu
     * @param people liste des personnes présentes dans le lieu
     * @return true si la personne est en sécurité, false sinon
     */
    bool isSafe(const Container &container) const override;

private:
    const Person *dependsOn;
    const Person *badWith;
};


#endif //LABO3_DEPENDENTPERSON_HPP


/* --------------------------------------------------------------------- */

#include "dependentPerson.hpp"
#include "../Containers/container.hpp"

DependentPerson::~DependentPerson() = default;

DependentPerson::DependentPerson(const std::string &name, const Person &dependsOn,
                                 const Person &badWith) : Person(name) {
    this->dependsOn = &dependsOn;
    this->badWith = &badWith;
}

bool DependentPerson::isSafe(const Container &container) const {
    bool isSafe = true;
    for (auto it = container.begin(); it != container.end(); ++it) {
        if (*it == this->dependsOn) {
            isSafe = true;
            break;
        } else if (*it == this->badWith) {
            isSafe = false;
        }
    }
    return isSafe;
}

/* --------------------------------------------------------------------- */

#ifndef LABO3_GIRL_HPP
#define LABO3_GIRL_HPP

#include "dependentPerson.hpp"




/**
 * Classe représentant la classe Girl
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Girl : public DependentPerson{
public:

    /**
     * Constructeur de la classe Girl
     * @param name nom de la personne
     * @param dependsOn personne dont la personne dépend
     * @param badWith personne avec laquelle elle ne peut pas rester
     */
    Girl(const std::string& name,const Person& dependsOn, const Person& badWith);

    /**
     * Méthode permettant d'avoir un message d'erreur lié à la personne
     * @return un message d'erreur
     */
    std::string getErrorMessage()const override;
private:
    static const std::string ERROR_MESSAGE;
};


#endif //LABO3_GIRL_HPP


/* --------------------------------------------------------------------- */

#include "girl.hpp"

const std::string Girl::ERROR_MESSAGE = "fille avec son pere sans sa mere";

Girl::Girl(const std::string &name,const Person &dependsOn,const Person &badWith) :
DependentPerson(name,dependsOn,badWith) {}

std::string Girl::getErrorMessage() const {
    return ERROR_MESSAGE;
}

/* --------------------------------------------------------------------- */

#ifndef LABO3_BOY_HPP
#define LABO3_BOY_HPP

#include "dependentPerson.hpp"

/**
 * Classe représentant un garcon
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Boy : public DependentPerson {
public:
    /**
     * Constructeur de la classe Boy
     * @param name nom de la personne
     * @param dependsOn personne dont il dépend
     * @param badWith personne avec qui il ne peut pas rester
     */
    Boy(const std::string &name, const Person &dependsOn, const Person &badWith);

	/**
	 * Méthode permettant d'avoir un message d'erreur lié à la personne
    * @return un message d'erreur
	 */
    std::string getErrorMessage() const override;

private:
    static const std::string ERROR_MESSAGE;
};


#endif //LABO3_BOY_HPP


/* --------------------------------------------------------------------- */

#include "boy.hpp"

const std::string Boy::ERROR_MESSAGE = "garcon avec sa mere sans son pere";

Boy::Boy(const std::string &name, const Person &dependsOn, const Person &badWith) :
        DependentPerson(name, dependsOn, badWith) {

}

std::string Boy::getErrorMessage() const {
    return ERROR_MESSAGE;
}