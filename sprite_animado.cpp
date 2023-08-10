#include "sprite_animado.h"
#include <iostream>


Sprite_animado::Sprite_animado(std::string const& name): name(name){ }


void Sprite_animado::init()
{
    std::ostringstream sstream;
    sstream << name << "_" << cont_sprite << ".txt";
    std::ifstream arquive(sstream.str());
    std::string line;
    if(arquive.is_open())
    {
        while(getline(arquive, line))
        {
           sprite.push_back(line); 
        }
    }
    cont_sprite++;
    arquive.close();

}

void Sprite_animado::update()
{
    sprite.clear();

    std::ostringstream sstream;
    sstream << name << "_" << cont_sprite << ".txt";

    std::ifstream arquive(sstream.str());
    std::string line;
    if(arquive.is_open())
    {
        while(getline(arquive, line))
        {
           sprite.push_back(line); 
        }
    }
    else 
    {
        cont_sprite = 1;
        std::ostringstream sstream;
        sstream << name << "_" << 1 << ".txt";
        arquive.open(sstream.str());

        if(arquive.is_open())
        {
            while(getline(arquive, line))
            {
               sprite.push_back(line); 
            }
        }

    }
    cont_sprite++;
    arquive.close();
}

void Sprite_animado::draw()
{

}
