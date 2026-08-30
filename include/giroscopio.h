//
// Created by David Aaron Ojeda Camacho on 08/02/26.
//
#ifndef CODE_COMPU_VUELO_2_0_GIROSCOPIO_H
#define CODE_COMPU_VUELO_2_0_GIROSCOPIO_H
#include <arduino.h>
    class acelerometro {
        public:
            acelerometro();
            struct {
                int16_t Ax;
                int16_t Ay;
                int16_t Az;
            }acc;
            void acelerometer();
    };
    class giroscopio: public acelerometro {
        public:
            giroscopio();
            void gyroscope();
            void acelerometer();
            struct {
                 int16_t Gx;
                 int16_t Gy;
                 int16_t Gz;
            }gyro;
            void giros();
            struct {
                float Gx;
                float Gy;
                float Gz;
                float Ax;
                float Ay;
                float Az;
            }orientacion;
            //Por si te confundes esto es lo del GPS
        private:
            float &Gx = orientacion.Gx;
            float &Gy = orientacion.Gy;
            float &Gz = orientacion.Gz;
            float &Ax = orientacion.Ax;
            float &Ay = orientacion.Ay;
            float &Az = orientacion.Az;
            String(Gx);
    };
        //continua mañana que me dio hueva

#endif //CODE_COMPU_VUELO_2_0_GIROSCOPIO_H