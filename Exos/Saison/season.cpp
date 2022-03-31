//
// Created by Jonathan on 31.03.2022.
//

#include <cstring>
#include "season.hpp"
const Season Season::Spring  = Season("Spring");
const Season Season::Summer  = Season("Summer");
const Season Season::Autumn  = Season("AutumnFalls");
const Season Season::Winter  = Season("Winter");
unsigned counter = 0;


Season::Season(const char* n) {
    size_t len = strlen(n);
    char* tmp = new char[len + 1];
    strcpy(tmp, n);
    _name = tmp;
    ord = counter++;
}

const Season* Season::seasons[]{
        &Season::Spring,
        &Season::Summer,
        &Season::Autumn,
        &Season::Winter
};

const char * Season::name(){
    return _name;
}

unsigned Season::size(){
    return counter;
}