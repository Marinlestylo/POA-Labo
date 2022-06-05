#ifndef BUFFY_POSITION_HPP
#define BUFFY_POSITION_HPP

/**
 * Classe représentant une position dans le field
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Position {
public:
   /**
    * Retourne la distance euclidienne entre deux positions
    * @param from Position de départ
    * @param to   Position de la destination
    * @return un entier représentant la distance euclidienne entre deux positions
    */
   static int getEuclideanDistance(Position& from, Position& to);

   /**
    * Constructeur de base
    * @param x Position sur l'axe des x
    * @param y Position sur l'axe des y
    */
   Position(int x, int y);

   /**
    * @return la position sur l'axe des x
    */
   int getX() const;

   /**
    * @return la position sur l'axe des y
    */
   int getY() const;

   /**
    * Définit une nouvelle position aléatoire
    * @param maxX Valeur maximale sur l'axe des x
    * @param maxY Valeur maximale sur l'axe des y
    */
   void setRandomPosition(int maxX, int maxY);

   /**
    * Définit une nouvelle position se rapprochant de la position donnée
    * @param target Position cible
    * @param step   Nombre de pas possibles
    */
   void setDirectedPosition(Position& target, int step);

private :
   int x, y;
};

#endif //BUFFY_POSITION_HPP
