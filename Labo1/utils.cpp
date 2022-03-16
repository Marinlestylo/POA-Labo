//
// Created by Jonathan on 16.03.2022.
//

#include "utils.h"
#include <cstdlib>

unsigned randomNumber(unsigned mod) {
	return (unsigned)rand() % mod;
}

unsigned floorMod(long long a,unsigned b){
	a %= (long long)b;
	return unsigned (a < 0 ? a + (long long)b : a);
}
