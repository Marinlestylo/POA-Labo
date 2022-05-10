#ifndef LABO3_CONTROLLER_HPP
#define LABO3_CONTROLLER_HPP

#include <string>
#include <list>
#include "container.hpp"
#include "bank.hpp"
#include "person.hpp"
#include "boy.hpp"
#include "girl.hpp"
#include "dependentPerson.hpp"
#include "driver.hpp"
#include "thief.hpp"
#include "boat.hpp"

class Controller {
public:
    /**
     * Constructeur par défaut de la classe Controller
     */
    explicit Controller();

    /**
     * destructeur de la classe Controller
     */
    ~Controller();

    /**
     * Méthode permettant de lancer la boucle de jeu
     */
    void nextTurn();

    /**
     * Méthode permettant d'afficher un message d'erreur
     * @param errorMsg le message d'erreur
     */
    static void showError(const std::string &errorMsg);

private:

    /**
     * Crée le bateau, les deux rives ainsi que tous les personnages du jeu.
     */
    void initVariables();

    /**
     * Métode permettant d'embarquer un personnage sur le bateau
     * @param p le personnage à embarquer
     */
    void embark(Person &p);

    /**
     * Méthode permettant de débarquer un personnage du bateau
     * @param p le personnage à débarquer
     */
    void disembark(Person &p);

    /**
    * Méthode permettant d'afficher l'état du jeu
    */
    void display() const;

    /**
     * Méthode permettant d'afficher le menu
    */
    void showMenu() const;

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
     * Méthode permettant d'afficher une ligne du menu
     * @param command nom de la commande
     * @param info description de la commande
     */
    static void printMenuLine(const std::string &command, const std::string &info);

    /**
     * Méthode permettant de convertir un string en personne
     * @param s le string à convertir
     * @return le personnage correspondant au string
     */
    Person *compareStringToPerson(const std::string &s) const;

    /**
     * Méthode permettant de changer un personnage de container
     * @param p personnage à changer de place
     * @param toAdd lieu ou ajouter le personnage
     * @param addFrom lieu ou enlever le personnage
     */
    void changeLocation(Person &p, Container &toAdd, Container &addFrom);

    /**
     * Méthode permettant de savoir si le jeu est terminé
     * @return vrai si le jeu est terminé
     */
    bool endOfGame() const;


    int turn;
    bool gameRunning;
    Bank *leftBank, *rightBank;
    Boat *boat;
    std::list<Person *> people;
    static const std::string ERROR_MESSAGE, SEPARATOR;
};


#endif //LABO3_CONTROLLER_HPP
