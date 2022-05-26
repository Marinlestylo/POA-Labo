//
// Created by Lazar on 26.05.2022.
//

#ifndef BUFFY_UTILS_HPP
#define BUFFY_UTILS_HPP

class Utils {
public:
   static unsigned Random(unsigned max);

   Utils(Utils &other) = delete;
   void operator=(Utils &other) = delete;

private:
   Utils() = default;
};

#endif //BUFFY_UTILS_HPP
