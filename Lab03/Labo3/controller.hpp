//
// Created by Jonathan on 14.04.2022.
//

#ifndef LABO3_CONTROLLER_HPP
#define LABO3_CONTROLLER_HPP

#include <string>
#include "container.hpp"
#include "bank.hpp"
#include "person.hpp"
#include "parent.hpp"
#include "child.hpp"
#include "policeman.hpp"
#include "thief.hpp"
#include "boat.hpp"
#include <list>

class Controller {
public:
	/**
	 * Constructeur par défaut de la classe Controller
	 */
	explicit Controller();

	/**
	 * Crée le bateau, les deux rives ainsi que tous les personnages.
	 */
	void initVariables();


	/**
	 * method that display the shore and the boat
	 */
	void display();

	/**
	 * method that display the menu
	 * possible inputs:
	 * p - print the shore and the boat
	 * e <name> embark person in boat
	 * d <name> disembark person from boat
	 * q - quit
	 * m - move boat
	 * h - menu
	 * r - reset
	*/
	void showMenu();

	/**
	 * Incrémente le compteur de tour
	 */
	void nextTurn();

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
	void parseInput(std::string input);

	/**
	 * Permet de remttre le jeu dans son état initiale afin de le recommencer
	 */
	void reset();

	/**
	 * Affiche l'état du jeu
	 */
	void showBoard();

	/**
	 * Lance la boucle de jeu
	 */
	void gameLoop();

	/**
	 * Récupère l'input du joueur
	 * @return input du joueur
	 */
	void userInput();

private:
	void printMenuLine(const std::string& command, const std::string& info);

	bool checkInputWithParam(const std::string& input, const std::string& command);

	bool compareStringToPerson(const std::string& s);

	int turn;
	Bank* leftBank, * rightBank;
	Boat* boat;
	std::list<Person*> people;
	static const std::string ERROR_MESSAGE, SEPARATOR;
};


#endif //LABO3_CONTROLLER_HPP
