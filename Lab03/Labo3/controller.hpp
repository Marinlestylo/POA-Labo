//
// Created by Jonathan on 14.04.2022.
//

#ifndef LABO3_CONTROLLER_HPP
#define LABO3_CONTROLLER_HPP

#include <string>
#include "container.hpp"
#include "bank.hpp"
#include "boat.hpp"
#include <list>

class Controller {
public:
    /**
     * Constructeur par défaut de la classe Controller
     */
    explicit Controller();
    /**
     * Creates a new boat and a two new banks. Also creates all the people in the
     * game
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
    int turn;
    Bank leftBank,rightBank;
    Boat boat;
    std::list<Person*> people;

};


#endif //LABO3_CONTROLLER_HPP
