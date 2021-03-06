#ifndef BUFFY_CONSOLEDISPLAYER_HPP
#define BUFFY_CONSOLEDISPLAYER_HPP

#include <vector>
#include "Displayer.hpp"

/**
 * Classe gérant l'affichage d'une simulation dans une console
 *
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class ConsoleDisplayer : public Displayer {
public:
   /**
    * Constructeur de base
    * @param width  largeur de la grille
    * @param height hauteur de la grille
    */
   ConsoleDisplayer(unsigned width, unsigned height);

   void displayGrid(std::list<Humanoid*>::const_iterator begin,
                    std::list<Humanoid*>::const_iterator end) override;

   void displayPrompt(int turn) override;

   bool getInput(Field& f, Simulator& s) override;

private:
   /**
    * Met à jour la grille en itérant sur la liste des humanoïdes
    * @param begin Itérateur sur le premier élément de la liste des humanoïdes
    * @param end   Itérateur sur le dernier élément de la liste des humanoïdes
    */
   void updateGrid(std::list<Humanoid*>::const_iterator begin,
                   std::list<Humanoid*>::const_iterator end);

   std::vector<std::vector<char>> grid;
};

#endif //BUFFY_CONSOLEDISPLAYER_HPP
