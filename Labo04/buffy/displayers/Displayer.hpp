#ifndef BUFFY_DISPLAYER_HPP
#define BUFFY_DISPLAYER_HPP

#include <list>
#include "../humanoids/Humanoid.hpp"

class Simulator;

/**
 * Classe abstraite gérant l'affichage d'une simulation
 *
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Displayer {
public:
   /**
    * Constructeur de base
    * @param width  largeur de la grille
    * @param height hauteur de la grille
    */
   Displayer(unsigned width, unsigned height);

   /**
    * Destructeur virtuel par défaut
    */
   virtual ~Displayer() = default;

   /**
    * Affiche la grille de la simulation
    * @param begin Itérateur sur le premier élément de la liste des humanoïdes
    * @param end   Itérateur sur le dernier élément de la liste des humanoïdes
    */
   virtual void displayGrid(std::list<Humanoid*>::const_iterator begin,
                            std::list<Humanoid*>::const_iterator end) = 0;

   /**
    * Affiche le prompt
    * @param turn Nombre de tours effectués
    */
   virtual void displayPrompt(int turn) = 0;

   /**
    * Récupère de l'input de l'utilisateur
    * @param field     Field contenant les humanoïdes
    * @param simulator Simulateur actuel
    * @return true si l'utilisateur souhaite quitter la simulation
    */
   virtual bool getInput(Field& field, Simulator& simulator) = 0;

protected:
   /**
    * @return la largeur de la grille
    */
   unsigned getWidth() const;

   /**
    * @return la hauteur de la grille
    */
   unsigned getHeight() const;

private:
   const unsigned width, height;
};

#endif //BUFFY_DISPLAYER_HPP
