//
// Created by David Aaron Ojeda Camacho on 27/01/26.
//

#ifndef CODE_COMPU_VUELO_2_0_COMMANDS_H
#define CODE_COMPU_VUELO_2_0_COMMANDS_H
#include <string>
namespace N {
    class codigos {
        public:
            codigos();
            struct {
                int code = 0000;
                int counter;
                std::string text;
            } comando;
            void comandos();
            void girosvariable();
            std::string texto = comando.text;
    };
}
#endif //CODE_COMPU_VUELO_2_0_COMMANDS_H
