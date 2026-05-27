//
// Created by David Aaron Ojeda Camacho on 10/02/26.
//

#ifndef CODE_COMPU_VUELO_2_0_MICROSD_H
#define CODE_COMPU_VUELO_2_0_MICROSD_H
#include <Arduino.h>
    class microsd {
    public:
        microsd();
        String message;
        void guardado();
        void contador();
        struct {
            float segundos = 0;
        }tiempo;
        void archivo();
    };


#endif //CODE_COMPU_VUELO_2_0_MICROSD_H