#ifndef BUFFY_ACTION_HPP
#define BUFFY_ACTION_HPP

class Field;

class Humanoid;

/**
 * Classe représentant une action effectuée par un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Action {
public:
   /**
    * Constructeur de base
    * @param target      la cible de l'action
    */
   explicit Action(Humanoid* target);

   /**
    * Destructeur virtuel par défaut
    */
   virtual ~Action() = default;

   /**
    * Exécute l'action sur le field correspondant
    * @param field Field actuel de la simulation
    */
   virtual void execute(Field& field) = 0;

protected:
   /**
    * @return un pointeur sur la cible de l'action
    */
   Humanoid* getTarget() const;

private:
   Humanoid* target;
};

#endif //BUFFY_ACTION_HPP
