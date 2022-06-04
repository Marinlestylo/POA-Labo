//
// Created by Lazar on 19.05.2022.
//
#ifndef BUFFY_HUMAN_HPP
#define BUFFY_HUMAN_HPP

#include "Humanoid.hpp"

class Human : public Humanoid {
public:
   Human(int x, int y);

   void setAction(const Field& field) override;

   Identifier getIdentifier() const override;
};

#endif //BUFFY_HUMAN_HPP
