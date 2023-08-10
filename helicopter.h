#ifndef HELICOPTER
#define HELICOPTER

#include "objeto_jogo.h"

class Helicopter : public Objeto_jogo
{
public:
    Helicopter(): Objeto_jogo("sprites/hel", 2, 26, 5, 'h'){}
};

#endif // HELICOPTER
