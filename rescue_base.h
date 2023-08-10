#ifndef RESCUE_BASE 
#define RESCUE_BASE 

#include "objeto_jogo.h"

class Rescue_base : public Objeto_jogo
{
public:
    Rescue_base(): Objeto_jogo("sprites/base.txt", 1, 13, 5, 'b'){}
};

#endif // RESCUE_BASE 
