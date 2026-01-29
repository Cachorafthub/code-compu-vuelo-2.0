//declaración de librerias
#include <Arduino.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include "FS.h"
#include "SD.h"
#include <SPI.h>
#include <TinyGPSPlus.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP085.h>
#include <commands.h>
using namespace N;
void setup() {
    Serial.print("Inicializando computadora");
    for (int i = 0; i < 4; i++) {
        Serial.println(".");
        delay(500);
    }

}

void loop() {

}
