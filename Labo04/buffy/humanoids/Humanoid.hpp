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
    * Constructeur de base
    * @param x Position sur l'axe des x
    * @param y Position sur l'axe des y
    */
   Humanoid(int x, int y);

   /**
    * Destructeur par défaut s'assurant de supprimer l'action
    */
   virtual ~Humanoid();

   /**
    * Désactive le constructeur de copie
    * @param other humanoïde à copier
    */
   Humanoid(const Humanoid& other) = delete;

   /**
    * Désactive l'opérateur d'affectation
    * @param other humanoïde à affecter
    */
   Humanoid& operator=(const Humanoid& other) = delete;

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
    * @param isAlive nouvel état de l'humanoïde
    */
   void setAlive(bool isAlive);

   /**
    * Exécute l'action de l'humanoïde
    * @param field Field sur lequel l'action est effectuée
    */
   void executeAction(Field& field);

   /**
    * Définit l'action de l'humanoïde en fonction du contenu du field
    * @param field Field sur lequel l'action est définie
    */
   virtual void setAction(const Field& field);

   /**
    * @return un symbole représentant l'humanoïde
    */
   virtual char getSymbol() const = 0;

protected:

   /**
    * Setter protected pour définir l'attribut newAction
    * @param newAction nouvelle newAction
    */
   void setAction(Action* newAction);

private:
   Action* action;
   bool alive;
   Position position;
};

#endif //BUFFY_HUMANOID_HPP
