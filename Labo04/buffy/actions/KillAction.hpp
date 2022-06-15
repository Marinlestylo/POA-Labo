#ifndef BUFFY_KILLACTION_HPP
#define BUFFY_KILLACTION_HPP

#include "Action.hpp"

/**
 * Classe représentant une action qui tue un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class KillAction : public Action {
public:
   /**
    * Constructeur de base
    * @param target      la cible de l'action
    */
   explicit KillAction(Humanoid* target);

   void execute(Field& f) override;
};

#endif //BUFFY_KILLACTION_HPP
