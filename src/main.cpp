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

#define I2C_SDA 8
#define I2C_SCL 9
TwoWire I2CBME = TwoWire(0);

void setup() {
I2CBME.begin(I2C_SDA, I2C_SCL, 100000);
}

void loop() {

}
