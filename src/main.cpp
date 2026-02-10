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
#include "giroscopio.h"
#include "GPS.h"
#include "barometro.h"
using namespace G;
using namespace N;
using namespace P;
using namespace B;
codigos comunicacion;
MPU6050 mpu;
giroscopio giro;
GPS gps;
barometro bar;

void setup() {
    Serial.begin(115200);
    Serial.print("Inicializando computadora");
    for (int i = 0; i < 4; i++) {
        Serial.print(".");
        delay(500);
    }
    Serial.println(".");

}

void loop() {
    Serial.print("Codigo: ");
    Serial.print(comunicacion.texto.data());
    comunicacion.comandos();
    giro.gyroscope();
    gps.posicion();
    bar.baro();
    //todo meter los futuros void de los archivos con cada función
    //todo checar como acomodar todo la neta
}
