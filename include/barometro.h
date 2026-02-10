//
// Created by David Aaron Ojeda Camacho on 10/02/26.
//

#ifndef CODE_COMPU_VUELO_2_0_BAROMETRO_H
#define CODE_COMPU_VUELO_2_0_BAROMETRO_H
#include <arduino.h>
namespace B {
    class barometro {
    public:
        barometro();
        struct {
            String Temp;
            String Press;
            String Altitude;
        }bar;
        String &temp = bar.Temp;
        String &press = bar.Press;
        String &altitude = bar.Altitude;
        void baro();
    };
}
#endif //CODE_COMPU_VUELO_2_0_BAROMETRO_H