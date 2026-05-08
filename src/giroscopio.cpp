//
// Created by David Aaron Ojeda Camacho on 07/02/26.
//
#include <arduino.h>
#include "giroscopio.h"
#include <iostream>
#include "MPU6050.h"
using namespace G;
giroscopio::giroscopio() {};
MPU6050 sensor;
void giroscopio::giros() {
    sensor.getRotation(&gyro.Gx, &gyro.Gy, &gyro.Gz);
    orientacion.Gx = gyro.Gx * (250.0/32768.0);
    orientacion.Gy = gyro.Gy * (250.0/32768.0);
    orientacion.Gz = gyro.Gz * (250.0/32768.0);
}

void giroscopio::acelerometro() {
    sensor.getAcceleration(&acc.Ax, &acc.Ay, &acc.Az);
    orientacion.Ax = acc.Ax * (9.81/16384.0);
    orientacion.Ay = acc.Ay * (9.81/16384.0);
    orientacion.Az = acc.Az * (9.81/16384.0);
}

void giroscopio::gyroscope() {
    giros();
    acelerometro();
    delay(100);
}

