#ifndef LABO3_CONTROLLER_HPP
#define LABO3_CONTROLLER_HPP

#include <string>
#include <list>
#include "Containers/container.hpp"
#include "Containers/bank.hpp"
#include "Characters/person.hpp"
#include "Characters/boy.hpp"
#include "Characters/girl.hpp"
#include "Characters/dependentPerson.hpp"
#include "Characters/driver.hpp"
#include "Characters/thief.hpp"
#include "Containers/boat.hpp"

/**
 * Classe représentant le controller du jeu
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Controller {
public:
    /**
     * Constructeur par défaut de la classe Controller
     */
    Controller();

    /**
     * Opérateur d'affectation de la classe Controller
     */
    void operator=(const Controller&) = delete;

	 /**
	  * Impossibilité d'utiliser le constructeur de copie
	  * @param other
	  */
	 Controller(const Controller& other) = delete;

    /**
     * destructeur de la classe Controller
     */
    ~Controller();

    /**
     * Méthode permettant d'afficher un message d'erreur
     * @param errorMsg le message d'erreur
     */
    static void showError(const std::string &errorMsg);

    /**
     * Méthode permettant de gérer le début du jeu
     */
    void startGame();
private:

    /**
     * Méthode permettant de lancer la boucle de jeu
     */
    void nextTurn();

    /**
     * Crée le bateau, les deux rives ainsi que tous les personnages du jeu.
     */
    void initVariables();

    /**
     * Méthode finissant un tour de jeu
     */
    void endTurn();

    /**
     * Métode permettant d'embarquer un personnage sur le bateau
     * @param p le personnage à embarquer
     */
    void embark(const Person *p);

    /**
     * Méthode permettant de débarquer un personnage du bateau
     * @param p le personnage à débarquer
     */
    void disembark(const Person *p);

    /**
     * Méthode permettant de déplacer le bateau de rive
     */
    void moveBoat();

    /**
    * Méthode permettant d'afficher l'état du jeu
    */
    void display() const;

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
    * Méthode permettant d'afficher le menu
    */
    static void showMenu();

    /**
     * Méthode permettant d'afficher une ligne du menu
     * @param command nom de la commande
     * @param info description de la commande
     */
    static void printMenuLine(char command, const std::string &info, const
    std::string &argument = "");

    /**
     * Méthode permettant de convertir un string en personne
     * @param s le string à convertir
     * @return le personnage correspondant au string
     */
    const Person *compareStringToPerson(const std::string &s) const;

    /**
     * Méthode permettant de changer un personnage de container
     * @param p personnage à changer de place
     * @param toAdd lieu ou ajouter le personnage
     * @param addFrom lieu ou enlever le personnage
     */
    void changeLocation(const Person &p, Container &toAdd, Container &addFrom);

    /**
     * Méthode permettant de savoir si le jeu est terminé
     * @return vrai si le jeu est terminé
     */
    bool endOfGame() const;


    int turn;
    bool gameRunning;
    Bank *leftBank, *rightBank;
    Boat *boat;
    std::list<const Person *> people;
    static const std::string ERROR_MESSAGE, SEPARATOR;
    static const char DISPLAY = 'p', EMBARK = 'e', DISEMBARK = 'd', MOVE = 'm' ,
    RESET ='r',EXIT = 'q', HELP = 'h';
};


#endif //LABO3_CONTROLLER_HPP
