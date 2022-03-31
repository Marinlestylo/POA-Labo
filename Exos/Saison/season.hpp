//
// Created by Jonathan on 31.03.2022.
//

#ifndef SAISON_SEASON_HPP
#define SAISON_SEASON_HPP

class Season {
public:
    const static Season Spring;
    const static Season Summer;
    const static Season Autumn;
    const static Season Winter;
    const char* name();
    Season* values();
    static unsigned size();
    Season next();

private:
    Season(const char* name);
    static const Season* seasons[];
    const char* _name;
    unsigned ord;
    static unsigned counter;
};


#endif //SAISON_SEASON_HPP
