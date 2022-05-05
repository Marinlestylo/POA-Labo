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
    turn = 0;

}

void Controller::nextTurn() {
    turn++;
}

void Controller::showMenu() {

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
void Controller::parseInput(char input) {

    switch (input) {
        case 'p':
            printShore();
            printBoat();
            break;
        case 'e':
            embark();
            break;
        case 'd':
            disembark();
            break;
        case 'q':
            quit();
            break;
        case 'm':
            moveBoat();
            break;
        case 'h':
            showMenu();
            break;
        case 'r':
            reset();
            break;
        default:
            cout << "Invalid input" << endl;
            break;
    }
}

