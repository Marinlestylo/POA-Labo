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
    for(Person* p : people){
        delete p;
    }
    people.clear();
}

void Controller::initVariables() {
    Driver* mother = new Driver("mere");
    Driver* father = new Driver("pere");
    Boy* paul = new Boy("paul", *father, *mother);
    Boy* pierre = new Boy("pierre", *father, *mother);
    Girl* julie = new Girl("julie", *mother, *father);
    Girl* jeanne =  new Girl("jeanne", *mother, *father);
    Driver * policeman = new Driver("policier");
    Thief * thief = new Thief("voleur", *policeman);
    this->people = {mother,father,paul, pierre, julie, jeanne, policeman, thief};
	turn = 0;
	leftBank = new Bank("Gauche", people);
	rightBank = new Bank("Droite", std::list<Person*>());
	boat = new Boat(*leftBank);
    gameRunning = true;
}

void Controller::showMenu() const {
	printMenuLine("p", "afficher");
	printMenuLine("e <nom>", "embarquer <nom>");
	printMenuLine("d <nom>", "debarquer <nom>");
	printMenuLine("m", "deplacer bateau");
	printMenuLine("r", "reinitialiser");
	printMenuLine("q", "quitter");
	printMenuLine("h", "menu");
}

void Controller::nextTurn() {
    while(gameRunning){
        userInput();
    }
}

void Controller::parseInput(const std::string& input) {
    char command;
    Person* person = nullptr;
    if(input.empty() || input.size() > 1 && input[1] != ' ') {
        std::cout << ERROR_MESSAGE << std::endl;
        return;
    } else if(input.size() > 1) {
        person = compareStringToPerson(input.substr(2));
        if(person == nullptr) {
            std::cout << ERROR_MESSAGE  << std::endl;
            return;
        }
    }
    command = input[0];

    switch (command) {
        case 'p': break;
        case 'e': embark(*person); ++turn; break;
        case 'd': disembark(*person);++turn; break;
        case 'm':
            if(boat->isDockedOnthisBank(*leftBank))
                boat->moveBoat(*rightBank);
            else
                boat->moveBoat(*leftBank);
            ++turn;
            break;
        case 'r': reset(); break;
        case 'q': gameRunning = false; break;
        case 'h': showMenu(); break;
        default: std::cout << ERROR_MESSAGE;
    }
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
	for(Person* p : people){
		leftBank->addPerson(*p);
	}
	boat->moveBoat(*leftBank);
}

void Controller::userInput() {
	std::string input;
	std::cout << turn << "> ";
	getline(std::cin, input);
	parseInput(input);
}

void Controller::printMenuLine(const std::string& command, const std::string& info) {
	std::cout << std::setw(8) << std::left << command << ": " << info << std::endl;
}

Person* Controller::compareStringToPerson(const std::string& s) const {
	for (Person* p: people) {
		if (p->getName() == s){
            return p;
		}
	}
	return nullptr;
}

void Controller::embark(Person& p) {
	if(boat->isFull()){
		std::cout << "Le bateau est déjà plein" << std::endl;
	}else if(boat->getBank()->isMember(p)){
        changeLocation(p, *boat, *boat->getBank());
    }
}

void Controller::disembark(Person &p) {
    if(boat->isEmpty()){
        std::cout << "Le bateau est déjà vide" << std::endl;
    }else if(boat->isMember(p)){
        changeLocation(p, *boat->getBank(), *boat);
    }
    endOfGame();
}

void Controller::changeLocation(Person &p, Container& toAdd, Container& toRemove) {
    toAdd.addPerson(p);
    toRemove.removePerson(p);
    if(!(toAdd.isContainerSafe() && toRemove.isContainerSafe())){
        toAdd.removePerson(p);
        toRemove.addPerson(p);
    }
}

bool Controller::endOfGame() const {
    if (boat->isEmpty() && leftBank->isEmpty()) {
        std::cout << "Vous avez gagné !" << std::endl;
        return true;
    }
    return false;
}

void Controller::showError(const std::string& errorMsg) {
    std::cout << errorMsg << std::endl;
}





