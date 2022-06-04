//
// Created by Lazar on 19.05.2022.
//
#ifndef BUFFY_VAMPIRE_HPP
#define BUFFY_VAMPIRE_HPP

#include "Humanoid.hpp"

class Vampire : public Humanoid {
public:
   Vampire(int x, int y);

   void setAction(const Field& field) override;

   Identifier getIdentifier() const override;
};

#endif //BUFFY_VAMPIRE_HPP
