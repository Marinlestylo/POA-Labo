#ifndef BUFFY_SIMULATOR_HPP
#define BUFFY_SIMULATOR_HPP

#include <string>
#include "../displayers/Displayer.hpp"
#include "Field.hpp"
#include "utils/Random.hpp"

/**
 * Classe contrôlant la simulation du jeu
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Simulator {
public:
   /**
    * Constructeur de base
    * @param nbSimulation nombre de simulations à effectuer
    * @param width        largeur de la grille à afficher
    * @param height       hauteur de la grille à afficher
    * @param nbVampires   nombe de vampires
    * @param nbHumans     nombe de humains
    * @param displayer    affichage de la simulation
    */
   Simulator(unsigned nbSimulation, unsigned width, unsigned height, unsigned nbVampires,
             unsigned nbHumans, Displayer& displayer);

   /**
    * Destructeur par défaut
    */
   ~Simulator() = default;

   /**
    * @return le nombre de simulations à effectuer
    */
   unsigned getNbSimulation() const;

   /**
    * Lance une session graphique de simulation avec le displayer passé dans le constructeur
    */
   void run();

   /**
    * Simule des parties sur le nombre de simulations choisies et retourne le nombre de sauvetages
    * sur le nombre de simulations effectuées
    * @return le nombre de sauvetages sur le nombre de simulations effectuées
    */
   double simulate() const;

private:
   unsigned nbSimulation, width, height, nbVampires, nbHumans;
   Field field;
   Displayer& displayer;
   bool ended;
};

#endif //BUFFY_SIMULATOR_HPP
