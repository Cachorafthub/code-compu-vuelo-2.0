//
// Created by David Aaron Ojeda Camacho on 27/01/26.
//

#ifndef CODE_COMPU_VUELO_2_0_COMMANDS_H
#define CODE_COMPU_VUELO_2_0_COMMANDS_H
#include <string>
using namespace std;
namespace N {
    struct{
        int code = 0000;
        int counter;
        string text;
    }command;
    void comandos();
}
#endif //CODE_COMPU_VUELO_2_0_COMMANDS_H
