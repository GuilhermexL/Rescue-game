#ifndef PESSOA
#define PESSOA

#include "objeto_jogo.h"

class Person : public Objeto_jogo 
{
    public:
    Person(): Objeto_jogo("sprites/person", 2, 5, 3, 'p'){}

};


#endif // PESSOA


