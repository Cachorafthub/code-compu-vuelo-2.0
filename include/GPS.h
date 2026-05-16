//
// Created by David Aaron Ojeda Camacho on 09/02/26.
//

#ifndef CODE_COMPU_VUELO_2_0_GPS_H
#define CODE_COMPU_VUELO_2_0_GPS_H
#include <arduino.h>
    class GPS {
    public:
        GPS();
        struct {
            String locationlat;
            String locationlon;
        }coordenadas;
        void posicion();
        String &lat = coordenadas.locationlat;
        String &lon = coordenadas.locationlon;
    };

#endif //CODE_COMPU_VUELO_2_0_GPS_H