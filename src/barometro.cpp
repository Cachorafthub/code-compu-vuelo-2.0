//
// Created by David Aaron Ojeda Camacho on 10/02/26.
//

#include "arduino.h"
#include "Adafruit_BMP085.h"
#include "barometro.h"
using namespace B;
Adafruit_BMP085 bmp;
barometro::barometro() {};

void barometro::baro() {
    bar.Temp = bmp.readTemperature();
    bar.Press = bmp.readPressure();
    bar.Altitude = bmp.readAltitude();
}
