//
// Created by David Aaron Ojeda Camacho on 27/01/26.
//
#include <Arduino.h>
#include "../include/codigos.h"
#include <iostream>
#include <string>
using namespace N;
using namespace std;
codigos comando;
    void comandos() {
        Serial.println(comando.code);
        if (comando.code == 0000) {
            comando.counter = 1;
        }
        switch (comando.counter) {
            case 1:
                comando.text = "Idling";
                Serial.print(comando.text.data());
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
        //todo meter todos los casos y codigos posibles
    }