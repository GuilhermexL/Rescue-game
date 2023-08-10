#ifndef GAS
#define GAS

#include "objeto_jogo.h"

class Gas : public Objeto_jogo
{
public:
    Gas(): Objeto_jogo("sprites/gas.txt", 1, 16, 9, 'g'){}
};

#endif // GAS
