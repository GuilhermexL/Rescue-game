#include "objeto_jogo.h"

Objeto_jogo::Objeto_jogo(std::string const& sprite_name, int type, int size_x_, int size_y_,  char type_): size_x(size_x_), size_y(size_y_), type(type_)
{
    if(type == 1)
        sprite = new Sprite(sprite_name);
    else 
        sprite = new Sprite_animado(sprite_name);
}

Objeto_jogo::~Objeto_jogo()
{
    delete sprite;
}

void Objeto_jogo::move_to(int x, int y)
{
    if(x < 0 || y < 5)
        return;
    if(x + size_x < 170)
        this->x = x;
    if(y + size_y < 40)
        this->y = y;

}
void Objeto_jogo::active_toggle(bool toggle)
{
    active = toggle;
}

bool Objeto_jogo::colide(Objeto_jogo const& obj) const
{
    if((size_x - 7 + x) >= obj.get_x() && x + 7 <= obj.get_x())
        if((size_y + y) >= obj.get_y() && y <= obj.get_y())
            return true;
    return false;
}


void Objeto_jogo::init()
{
    sprite->init();
}

void Objeto_jogo::update()
{
    sprite->update();
}

void Objeto_jogo::draw()
{

}
