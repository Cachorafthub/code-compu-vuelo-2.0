//
// Created by David Aaron Ojeda Camacho on 10/02/26.
//
#include <Arduino.h>
#include  <FS.h>
#include <SD.h>
#include "microsd.h"
#include "giroscopio.h"
#include "codigos.h"
#include "GPS.h"
#include "barometro.h"
using namespace M;
using namespace G;
using namespace P;
using namespace B;
microsd::microsd() {};
giroscopio gyros;
GPS posicion;
barometro baromet;
#define SD_CS 5
void microsd::contador() {
    tiempo.segundos = tiempo.segundos+.5; //contador de segundos
    delay(500);
}

    void appendfile(fs::FS &fs, const char * path, const char * message){
        Serial.printf("Appending to file: %s\n", path);
        File file = fs.open(path, FILE_APPEND);
        if(!file) {
            Serial.println("Failed to open file for appending");
            return;
        }
        if(file.print(message)) {
            Serial.println("Message appended");
        } else {
            Serial.println("Append failed");
        }
        file.close();
    }


void writeFile(fs::FS &fs, const char * path, const char * message) {
    Serial.printf("Writing file: %s\n", path);
    File file = fs.open(path, FILE_WRITE);
    if(!file) {
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.print(message)) {
        Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}

void microsd::archivo() {
    SD.begin(SD_CS);
    if(!SD.begin(SD_CS)) {
        Serial.println("Card Mount Failed");
        return;
    }
    uint8_t cardType = SD.cardType();
    if(cardType == CARD_NONE) {
        Serial.println("No SD card attached");
        return;
    }
    Serial.println("Initializing SD card...");
    if (!SD.begin(SD_CS)) {
        Serial.println("ERROR - SD card initialization failed!");
        return;    // init failed
    }
    //crear archivo de datos en la micro sd
    File file = SD.open("/data.txt");
    if(!file) {
        Serial.println("File doens't exist");
        Serial.println("Creating file...");
        writeFile(SD, "/sensorinfo.txt", "segundos, aceleraciónx, aceleracióny, aceleraciónz, posiciónx, posicióny, posiciónz, latitud, longitud, temperatura, altitud, presion,  \r\n");
    }
    else {
        Serial.println("File already exists");
    }
    file.close();
}

void microsd::guardado() {
    microsd::message = String(tiempo.segundos) + "seg" + String(gyros.Ax) + "Ax" + String(gyros.Ay) + "Ay" +
        String(gyros.Az) + "Az" + String(gyros.Gx) + "Gx" + String(gyros.Gy) + "Gy" + String(gyros.Gz) + "Gz" +
        String(posicion.lat) + "lat" + String(posicion.lon) + "lon" + String(baromet.temp) +
            "temp" + String(baromet.altitude) + "altitude" + String(baromet.press) + "press" + "\r\n";
    Serial.print("Save data: ");
    Serial.println(microsd::message);
    appendfile(SD, "/sensorinfo.txt", microsd::message.c_str());
}

//todo transmisor a