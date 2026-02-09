//
// Created by David Aaron Ojeda Camacho on 27/01/26.
//
#include <Arduino.h>
#include "../include/codigos.h"
#include <iostream>
#include <string>
#include "giroscopio.h"
using namespace N;
using namespace G;
using namespace std;
codigos::codigos() {};
giroscopio giro;
float sum;
float sum2;

void codigos::girosvariable(){
    sum = giro.Gx + giro.Gy + giro.Gz;
    sum2 = giro.Ax + giro.Ay + giro.Az;
}


void codigos::comandos() {
        Serial.println(comando.code);
        if (comando.code == 0000) {
            comando.counter = 1;
        }

        if (sum == 0) {
            comando.counter = 2;
            comando.code = 0002;
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
                comando.text = "problemas en giroscopio";
                Serial.println(comando.text.data());
                Serial.println("favor de revisar computadora");
                break;

            case 3:
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


