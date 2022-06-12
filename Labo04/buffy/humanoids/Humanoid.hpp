#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "../actions/Action.hpp"
#include "../simulation/utils/Position.hpp"

/**
 * Classe abstraite représentant un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Humanoid {
public:
   /**
    * Destructeur par défaut s'assurant de supprimer l'action
    */
   virtual ~Humanoid();

   /**
    * Retourne la position de l'humanoïde
    * @return une référence sur la position
    */
   Position& getPosition();

   /**
    * @return true si l'humanoïde est vivant
    */
   bool isAlive() const;

   /**
    * Définit l'état de l'huanoïde
    * @param alive nouvel état de l'humanoïde
    */
   void setAlive(bool alive);

   /**
    * Exécute l'action de l'humanoïde
    * @param field Field sur lequel l'action est effectuée
    */
   void executeAction(Field& field);

   /**
    * Définit l'action de l'humanoïde
    * @param field Field sur lequel l'action est définie
    */
   virtual void setAction(const Field& field);

protected:
   /**
    * Constructeur de base protected pour rendre humanoïde abstrait
    * @param x Position sur l'axe des x
    * @param y Position sur l'axe des y
    */
   Humanoid(int x, int y);

   Action* action;
private:
   bool alive;
   Position position;
};

#endif //BUFFY_HUMANOID_HPP
