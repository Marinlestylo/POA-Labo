#include "tieHunter.hpp"

ShipCharacteristic TieHunter::characteristic(
        "TIE/LN", 100, 6
);

TieHunter::TieHunter() : Ship(&characteristic) {}