//
// Created by Jonathan on 14.04.2022.
//

#include "controller.hpp"
#include <iostream>

using namespace std;

Controller::Controller() {
    initVariables();
}

void Controller::initVariables() {
    this->people = {
        new Parent("mere",0),
        new Parent("pere",1),
        new Policeman("policier"),
        new Thief("voleur")
    };
    turn = 0;
    leftBank = new Bank("Gauche", people);
    rightBank = new Bank("Droite", people);
    boat = new Boat(leftBank);
}

void Controller::nextTurn() {
    turn++;
}

void Controller::showMenu() {
    cout << "p : afficher" << endl;
    cout << "e <nom>: embarquer <nom>" << endl;
    cout << "d <nom>: debarquer <nom>" << endl;
    cout << "m : deplacer bateau" << endl;
    cout << "r : reinitialiser" << endl;
    cout << "q : quitter" << endl;
    cout << "h : menu" << endl;

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
void Controller::parseInput(string input) {

    switch (input[0]) {
        case 'p':
            //printShore();
            //printBoat();
            cout << "p" << endl;
            break;
        case 'e':
            //embark();
            cout << "e" << endl;
            break;
        case 'd':
            //disembark();
            cout << "d" << endl;
            break;
        case 'q':
            cout << "Au revoir";
            exit(0);
        case 'm':
            //moveBoat();
            cout << "m" << endl;
            break;
        case 'h':
            showMenu();
            break;
        case 'r':
            //reset();
            cout << "r" << endl;
            break;
        default:
            cout << "Invalid input" << endl;
            break;
    }
}

void Controller::display() {

}

void Controller::reset() {

}

void Controller::userInput() {
    std::string input;
    cout << "Veuillez entrer votre input (Tapez \"h\" pour obtenir de l'aide): " << endl;
    getline(cin, input);
    parseInput(input);
}

