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
    people.clear();
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
        showError("Error: Bateau est plein ou personne n'as pas été trouvée");
    } else if (boat->isOnBank(*p)) {
        Bank *bank = boat->isDockedOnthisBank(*leftBank) ? leftBank : rightBank;
        changeLocation(*p, *boat, *bank);
    } else {
        showError("Error: Personne n'est pas sur la rive");
    }
}

void Controller::disembark(const Person *p) {
    if (boat->isEmpty()) {
        showError("Error: Le bateau est déjà vide");
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
        std::cout << "Vous avez gagné !" << std::endl;
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





