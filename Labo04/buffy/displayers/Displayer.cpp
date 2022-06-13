/**
 * Classe abstraite gérant l'affichage d'une simulation
 *
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Displayer.hpp"

using namespace std;

Displayer::Displayer(unsigned width, unsigned height) : width(width), height(height) {}

unsigned Displayer::getWidth() const {
   return width;
}

unsigned Displayer::getHeight() const {
   return height;
}
