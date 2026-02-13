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
#include "microsd.h"
using namespace G;
using namespace N;
using namespace P;
using namespace B;
using namespace M;
codigos comunicacion;
MPU6050 mpu;
giroscopio giro;
GPS gpss;
barometro bar;
Adafruit_BMP085 barom;
microsd micr;
#define SD_CS 5
#define RXD2 16
#define TXD2 17

#define GPS_BAUD 9600
HardwareSerial gpsSerial(2);


void setup() {

    Serial.begin(115200);
    Wire.begin();
    Serial.print("Inicializando computadora");
    for (int i = 0; i < 4; i++) {
        Serial.print(".");
        delay(500);
    }
    Serial.println(".");
    mpu.initialize();
    if (mpu.testConnection()) Serial.println("Sensor iniciado correctamente");
    else Serial.println("Error al iniciar el sensor");


    // Comunicación serial del GPS
    gpsSerial.begin(GPS_BAUD, SERIAL_8N1, RXD2, TXD2);
    Serial.println("Serial 2 started at 9600 baud rate");

    if (!barom.begin()) {
        Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
        while (1) {}
    }
    gpsSerial.begin(GPS_BAUD, SERIAL_8N1, RXD2, TXD2);
    Serial.println("Serial 2 started at 9600 baud rate");
    micr.archivo();
}

void loop() {
    Serial.print("Codigo: ");
    Serial.print(comunicacion.texto.data());
    micr.contador();
    comunicacion.comandos();
    giro.gyroscope();
    gpss.posicion();
    bar.baro();
    micr.guardado();
    //todo meter los futuros void de los archivos con cada función
    //todo checar como acomodar todo la netaaaaa
}
