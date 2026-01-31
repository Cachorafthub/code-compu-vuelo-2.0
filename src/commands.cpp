//
// Created by David Aaron Ojeda Camacho on 27/01/26.
//
#include <Arduino.h>
#include "../include/commands.h"
#include <iostream>
#include <string>
using namespace N;
using namespace std;

void comandos() {
    Serial.println(command.code);
    if (command.code == 0000) {
        command.counter = 1;
    }
    switch (command.counter) {
        case 1:
            command.text = "Idling";
            Serial.print(command.text.data());
            for (int i = 0; i < 3; i++) {
                Serial.println(".");
            }
            break;

        case 2:
            break;

        default:
            for (int i = 0; i < 2; i++) {
                Serial.println(
                    "No se ha detectado ningun estado, "
                    "favor de revisar la computadora en busca del algun error ");
            }
    }

}