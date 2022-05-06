//
// Created by Jonathan on 14.04.2022.
//

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

void Controller::initVariables() {
    Driver* mother = new Driver("mere");
    Driver* father = new Driver("pere");
    DependentPeople* paul = new DependentPeople("paul",father,mother);
    DependentPeople* pierre = new DependentPeople("pierre",father,mother);
    DependentPeople* julie = new DependentPeople("julie",mother,father);
    DependentPeople* jeanne =  new DependentPeople("marie-jeanne",mother,father);
    Driver * policeman = new Driver("policier");
    Thief * thief = new Thief("voleur");
    this->people = {paul, pierre, julie, jeanne, policeman, thief};
	turn = 0;
	leftBank = new Bank("gauche", people);
	rightBank = new Bank("droite", *(new std::list<Person*>()));
	boat = new Boat(leftBank);
}

void Controller::nextTurn() {
	turn++;
}

void Controller::showMenu() {
	printMenuLine("p", "afficher");
	printMenuLine("e <nom>", "embarquer <nom>");
	printMenuLine("d <nom>", "debarquer <nom>");
	printMenuLine("m", "deplacer bateau");
	printMenuLine("r", "reinitialiser");
	printMenuLine("q", "quitter");
	printMenuLine("h", "menu");
}

void Controller::showBoard() {

}

void Controller::parseInput(std::string input) {
	// On check d'abord tous les inputs de longueur 1
	if (input.size() == 1) {
		switch (input[0]) {
			case 'p':
				display();
				break;
			case 'q':
				std::cout << "Au revoir";
				exit(0);
			case 'm':
				if(boat->isDockedOnthisBank(leftBank))
					boat->moveBoat(rightBank);
				else
					boat->moveBoat(leftBank);
				break;
			case 'h':
				showMenu();
				break;
			case 'r':
				reset();
				break;
			default:
				std::cout << ERROR_MESSAGE << std::endl;
				break;
		}
		// On check maintenant les inputs plus "complexes"
	} else if (checkInputWithParam(input, "e ")) {
		//embark();
		std::cout << "e" << std::endl;
	} else if (checkInputWithParam(input, "d ")){
		//disembark();
		std::cout << "d" << std::endl;
	} else{
		std::cout << ERROR_MESSAGE << std::endl;
	}
}

void Controller::display() {
	std::cout << SEPARATOR << std::endl;
	leftBank->showContainer();
	std::cout << std::endl;
	boat->showContainer();
	std::cout << std::endl;
	rightBank->showContainer();
	std::cout << std::endl << SEPARATOR << std::endl;
}

void Controller::reset() {
	rightBank->emptyContainer();
	leftBank->emptyContainer();
	boat->emptyContainer();
	for(Person* p : people){
		leftBank->addPerson(p);
	}
	boat->moveBoat(leftBank);
}

void Controller::userInput() {
	std::string input;
	std::cout << "Veuillez entrer votre input :" << std::endl;
	getline(std::cin, input);
	parseInput(input);
}

void Controller::printMenuLine(const std::string& command, const std::string& info) {
	std::cout << std::setw(8) << std::left << command << ": " << info << std::endl;
}

bool Controller::compareStringToPerson(const std::string& s) {
	for (Person* p: people) {
		if (p->getName() == s)
			return true;
	}
	return false;
}

bool Controller::checkInputWithParam(const std::string& input,
												 const std::string& command) {
	std::string a = input.substr(0, 2);
	return a == command &&
				compareStringToPerson(input.substr(2));
}

