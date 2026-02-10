//
// Created by David Aaron Ojeda Camacho on 09/02/26.
//
#include <arduino.h>
#include "GPS.h"
#include "tinyGPSPlus.h"
using namespace std;
using namespace P;
TinyGPSPlus gps;
GPS::GPS() {};

void GPS::posicion() {
    unsigned long start = millis();

    while (millis() - start < 1000) {
        coordenadas.locationlat = String(gps.location.lat(), 6);
        coordenadas.locationlon = String(gps.location.lng(), 6);
    }
}
