//
// Created by Jonathan on 14.04.2022.
//

#include "controller.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

const string Controller::ERROR_MESSAGE = "Input invalide ! (Tapez \"h\" pour obtenir de l'aide) : ";


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
void Controller::parseInput(string input) {
    if(input.size() == 1){
        switch (input[0]) {
            case 'p':
                //printShore();
                //printBoat();
                cout << "p" << endl;
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
                cout << ERROR_MESSAGE << endl;
                break;
        }
    }else{
        switch (input[0]) {
            case 'e':
                //embark();
                cout << "e" << endl;
                break;
            case 'd':
                //disembark();
                cout << "d" << endl;
                break;
            default:
                cout << ERROR_MESSAGE << endl;
                break;
        }
    }
}

void Controller::display() {

}

void Controller::reset() {

}

void Controller::userInput() {
    std::string input;
    cout << "Veuillez entrer votre input :" << endl;
    getline(cin, input);
    parseInput(input);
}

void Controller::printMenuLine(const string &command, const string &info) {
    cout << std::setw(8) << left << command << ": " << info << endl;
}

