#include "tieInterceptor.hpp"

ShipCharacteristic TieInterceptor::characteristic(
        "TIE/IN", 110, 5
);

TieInterceptor::TieInterceptor() : Ship(&characteristic) {}