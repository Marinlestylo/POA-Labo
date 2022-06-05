#ifndef BUFFY_MOVEACTION_HPP
#define BUFFY_MOVEACTION_HPP

#include "Action.hpp"

/**
 * Classe représentant une action déplaçant un humanoïde aléatoirement ou vers une cible
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class MoveAction : public Action {
public:
   /**
    * Constructeur de base
    * @param actionMaker l'humanoïde qui effectue l'action
    * @param target      la cible de l'action
    * @param step        le nombre de pas possibles
    */
   MoveAction(Humanoid* actionMaker, Humanoid* target, unsigned step);

   void execute(Field& f) override;

private:
   int currentX, currentY;
   unsigned step;
};

#endif //BUFFY_MOVEACTION_HPP
