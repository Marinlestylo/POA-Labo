//
// Created by Jonathan on 14.04.2022.
//

#include "controller.hpp"
#include <iostream>
#include <iomanip>

const std::string Controller::ERROR_MESSAGE = "Input invalide ! (Tapez \"h\" pour "
															 "obtenir de l'aide) : ";


Controller::Controller() {
	initVariables();
}

void Controller::initVariables() {
	this->people = {
		new Parent("mere", 0),
		new Parent("pere", 1),
		new Child("paul", 1),
		new Child("pierre", 1),
		new Child("julie", 0),
		new Child("Marie-jeanne", 0),
		new Policeman("policier"),
		new Thief("voleur")
	};
	turn = 0;
	leftBank = new Bank("Gauche", people);
	rightBank = new Bank("Droite", *(new std::list<Person*>()));
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

/**
 * method that parse the input and call the corresponding method
 * possible inputs:
 * p - print the shore and the boat
 * e <name> embark person in boat
 * d <name> disembark person from boat
 * q - quit
 * m - move boat
 * h - menu
 * r - reset
*/
void Controller::parseInput(std::string input) {
	if (input.size() == 1) {
		switch (input[0]) {
			case 'p':
				//printShore();
				//printBoat();
				std::cout << "p" << std::endl;
				break;
			case 'q':
				std::cout << "Au revoir";
				exit(0);
			case 'm':
				//moveBoat();
				std::cout << "m" << std::endl;
				break;
			case 'h':
				showMenu();
				break;
			case 'r':
				//reset();
				std::cout << "r" << std::endl;
				break;
			default:
				std::cout << ERROR_MESSAGE << std::endl;
				break;
		}
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
}

void Controller::reset() {

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

