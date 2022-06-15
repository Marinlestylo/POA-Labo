#ifndef BUFFY_TRANSFORMACTION_HPP
#define BUFFY_TRANSFORMACTION_HPP

#include "Action.hpp"

/**
 * Classe représentant une action qui transforme un humanoïde en vampire
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class TransformAction : public Action {
public:
   /**
    * Constructeur de base
    * @param target      la cible de l'action
    */
   explicit TransformAction(Humanoid* target);

   void execute(Field& f) override;
};

#endif //BUFFY_TRANSFORMACTION_HPP
