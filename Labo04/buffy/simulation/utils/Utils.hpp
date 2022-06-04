//
// Created by Lazar on 26.05.2022.
//

#ifndef BUFFY_UTILS_HPP
#define BUFFY_UTILS_HPP

#include <string>
#include "../../humanoids/Humanoid.hpp"

enum DisplayType {
   CONSOLE, NO_DISPLAY
};

class Utils {
public:
   // TODO: Générateur random pour direction + pourcentage de chance de kill du vampire
   static unsigned random(unsigned max = 0);

   static DisplayType getDisplayType(const std::string& type);

   static double getEuclideanDistance(Humanoid* from, Humanoid* to);

   Utils(Utils& other) = delete;

   void operator=(Utils& other) = delete;

private:
   Utils() = default;
};

#endif //BUFFY_UTILS_HPP
