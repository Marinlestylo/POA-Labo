//
// Created by Lazar on 19.05.2022.
//

#include "Humanoid.hpp"

#ifndef BUFFY_BUFFY_HPP
#define BUFFY_BUFFY_HPP

class Buffy : public Humanoid {
public:
   Buffy(unsigned int posX, unsigned int posY);

   char getHuntedIdentifier() const;

   void setAction(const Field& field) override;

   char getIdentifier() const override;

};

#endif //BUFFY_BUFFY_HPP