//
// Created by David Aaron Ojeda Camacho on 27/01/26.
//
#include <Arduino.h>
#include "../include/codigos.h"
#include <iostream>
#include <string>
#include "giroscopio.h"
codigos::codigos() {};
giroscopio giros;
float sum;
float sum2;

void codigos::girosvariable(){
    sum = giros.Gx + giros.Gy + giros.Gz;
    sum2 = giros.Ax + giros.Ay + giros.Az;
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

        if (sum2 == 0) {
            comando.counter = 3;
            comando.code = 0003;
        }

        if (sum == 0 && sum2 == 0) {
            comando.counter = 4;
            comando.code = 0004;
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
                comando.text = "problemas en acelerometro";
                Serial.println(comando.text.data());
                Serial.println("favor de revisar computadora");
                break;

            case 4:
                comando.text = "problemas en acelerometro y giroscopio";
                Serial.println(comando.text.data());
                Serial.println("favor de revisar computadora");
                break;

            default:
                for (int i = 0; i < 2; i++) {
                    Serial.println(
                        "No se ha detectado ningun estado, "
                        "favor de revisar la computadora en busca del algun error ");
                }
        }
        //todo hacer algo con este codigo y poner casos
        //todo cambiar los codigos a if not casos

}


