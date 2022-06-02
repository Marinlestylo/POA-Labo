//
// Created by Lazar on 26.05.2022.
//

#ifndef BUFFY_UTILS_HPP
#define BUFFY_UTILS_HPP

#include <string>

enum DisplayType { CONSOLE, NO_DISPLAY };

class Utils {
public:

   static unsigned Random(unsigned max);
   static DisplayType getDisplayType(const std::string& type);
   Utils(Utils &other) = delete;
   void operator=(Utils &other) = delete;

private:
   Utils() = default;
};

#endif //BUFFY_UTILS_HPP
