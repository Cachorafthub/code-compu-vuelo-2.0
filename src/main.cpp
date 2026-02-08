//declaración de librerias
#include <../include/Adafruit_BMP085.h>
#include <Arduino.h>
#include <../include/codigos.h>
#include <SPI.h>
#include <../include/TinyGPSPlus.h>
#include "FS.h"
#include "../include/I2Cdev.h"
#include "../include/MPU6050.h"
#include "SD.h"
#include "Wire.h"

using namespace N;
codigos comunicacion;
MPU6050 mpu;

void setup() {
    Serial.begin(115200);
    Serial.print("Inicializando computadora");
    for (int i = 0; i < 4; i++) {
        Serial.println(".");
        delay(500);
    }
    Serial.print("Codigo: ");


}

void loop() {
    comunicacion.comandos();
    comunicacion.Ax = 10;
    //todo meter los futuros void de los archivos con cada función
    //todo checar como acomodar todo la neta
}
