//
// Created by Lazar on 02.06.2022.
//

#ifndef BUFFY_SIMULATOR_HPP
#define BUFFY_SIMULATOR_HPP

#include <string>
#include "../displayers/Displayer.hpp"
#include "Field.hpp"
#include "utils/Utils.hpp"

class Simulator {
public:
   Simulator(unsigned nbSimulation, unsigned width, unsigned height, unsigned nbVampires, unsigned
   nbHumans, Displayer*displayer);

   ~Simulator();

   unsigned getNbSimulation() const;

   void run();

   double simulate();

private:
   unsigned nbSimulation, width, height, nbVampires, nbHumans;
   Field field;
   Field* simulationField;
   Displayer* displayer;
   bool ended;
};

#endif //BUFFY_SIMULATOR_HPP
