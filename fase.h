#ifndef FASE 
#define FASE

#include "objeto_jogo.h" 
#include "sprite_base.h"
#include "helicopter.h"
#include "person.h"
#include "rescue_base.h"
#include "gas.h"

#include <vector>
#include <iostream>
#include <sstream>

class Fase : public Game_base
{
    Sprite_base* background;
    std::vector<Objeto_jogo *> objs;
    char buffer[2][40][170] = {' '};
    int cont_buffer = 0;
    int current_buffer = 1;

    int heli_charge = 2;
    int heli_charge_max = 2;
    int heli_fuel = 300;
    int heli_fuel_max = 300;
    int peoples = 2;

    public:
    Fase();

    int run();
    void show();
    void clear_buffer();
    void swap_buffer();
    
    void init() override;
    void update() override;
    void draw() override;

};


#endif // FASE
