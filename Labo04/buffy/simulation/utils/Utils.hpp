//
// Created by Lazar on 26.05.2022.
//

#ifndef BUFFY_UTILS_HPP
#define BUFFY_UTILS_HPP

#include <string>
#include <random>
#include "../../humanoids/Humanoid.hpp"

class Utils {
public:
   static unsigned random(unsigned max);

   Utils(Utils& other) = delete;

   void operator=(Utils& other) = delete;

private:
   Utils() = default;
};

#endif //BUFFY_UTILS_HPP
