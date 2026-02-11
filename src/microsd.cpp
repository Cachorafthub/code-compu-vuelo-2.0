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
barometro barom;
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

void appendFile(fs::FS &fs, const char * path, const char * message) {
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


void microsd::guardado() {
    microsd::message = String(gyros.Ax) + "Ax" + String(gyros.Ay) + "Ay" + String(gyros.Az)
        + "Az" + String(gyros.Gx) + "Gx" + String(gyros.Gy) + "Gy" + String(gyros.Gz) + "Gz" +
        String(posicion.lat) + "lat" + String(posicion.lon) + "lon" + String(barom.temp) +
            "temp" + String(barom.altitude) + "altitude" + String(barom.press) + "press" + "\r\n";
    Serial.print("Save data: ");
    Serial.println(microsd::message);
    appendFile(SD, "/sensorinfo.txt", microsd::message.c_str());
}

