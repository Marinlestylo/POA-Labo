//
// Created by Lazar on 19.05.2022.
//
#ifndef BUFFY_BUFFY_HPP
#define BUFFY_BUFFY_HPP

#include "Humanoid.hpp"

class Buffy : public Humanoid {
public:
   Buffy(unsigned int posX, unsigned int posY);

   void setAction(const Field& field) override;

   Identifier getIdentifier() const override;

};

#endif //BUFFY_BUFFY_HPP