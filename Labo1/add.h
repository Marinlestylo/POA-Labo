//
// Created by Jonathan on 03.03.2022.
//

#ifndef LABO1_ADD_H
#define LABO1_ADD_H

#include "operation.h"


class Add : public Operation{
public:
    int apply(int a, int b) const;
};


#endif //LABO1_ADD_H
