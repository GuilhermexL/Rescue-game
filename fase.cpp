#include "fase.h"
#include <stdlib.h>

Fase::Fase()
{
    init();
}

int Fase::run()
{
    char input;
    heli_fuel = heli_fuel_max;  // Adicionando a variável heli_fuel pra começar com 300 de combustível
    heli_charge = heli_charge_max;
    peoples = 5;
    
    while (true)
    {
        draw();
        show();
        std::cin >> input;
        heli_fuel -= 2;

        if (heli_fuel <= 0)  // Verificando se o combustível chegou a zero
        {
            return -1;
        }
        
        if (input == 'p')
        {
            std::cout << "Pause" << std::endl;
            std::cin >> input;
            
            while (input != 'p')
                std::cin >> input;
        }
        
        switch (input)
        {
            case 'a':
                objs[0]->move_to(objs[0]->get_x() - 4, objs[0]->get_y());
                break;
            case 'd':
                objs[0]->move_to(objs[0]->get_x() + 4, objs[0]->get_y());
                break;
            case 'w':
                objs[0]->move_to(objs[0]->get_x(), objs[0]->get_y() - 2);
                break;
            case 's':
                objs[0]->move_to(objs[0]->get_x(), objs[0]->get_y() + 2);
                break;
            case 'x':
                for (auto p : objs)
                {
                    if (p->get_type() == 'p')
                    {
                        if (objs[0]->colide(*p) && heli_charge > 0)
                        {
                            p->active_toggle(false);
                            heli_charge--;
                        }
                    }
                    else if (p->get_type() == 'b')
                    {
                        if (objs[0]->colide(*p))
                        {
                            peoples-=heli_charge_max - heli_charge;
                            heli_charge = heli_charge_max;                           
                        }
                    }
                    else if (p->get_type() == 'g')
                    {
                        if (objs[0]->colide(*p))
                        {
                            heli_fuel = heli_fuel_max;
                        }
                    }
                }
                break;
            case 'q':
                return 0;
        }
        
        update();
        
        if (peoples <= 0)  // Verificando se o número de pessoas chegou a zero
        {
            return 1;
        }
    }
}

void Fase::show()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 170; j++)
            std::cout << buffer[current_buffer][i][j];
        std::cout << std::endl;
    }

}

void Fase::init()
{
    background = new Sprite_animado("sprites/background");
    background->init();

    objs.push_back(new Helicopter());
    objs.push_back(new Person());
    objs.push_back(new Person());
    objs.push_back(new Person());
    objs.push_back(new Person());
    objs.push_back(new Person());
    objs.push_back(new Rescue_base());
    objs.push_back(new Gas());

    objs[0]->move_to(30, 7); //Helicóptero
    objs[1]->move_to(64, 36); //Pessoa
    objs[2]->move_to(160, 36); //Pessoa
    objs[3]->move_to(150, 36); //Pessoa
    objs[4]->move_to(140, 36); //Pessoa
    objs[5]->move_to(54, 36); //Pessoa
    objs[6]->move_to(13, 34); //Base
    objs[7]->move_to(105, 30); //Posto

    for(auto o: objs)
        o->init();

    clear_buffer();

}

void Fase::update()
{
    for(auto o: objs)
        o->update();
    background->update();
}

void Fase::draw() 
{
    for(auto o : objs)
    {
        Sprite_base const* sprite = o->get_sprite();
        if(!o->get_active())
            continue;
        for(int i = 0; i < o->get_size_y(); i++)
            for(int j = 0; j < o->get_size_x(); j++)
            {
                buffer[cont_buffer][i + o->get_y()][j + o->get_x()] = sprite->get_sprite()[i][j]; 
            }
    }

    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 170; j++)
            if(buffer[cont_buffer][i][j] == ' ')
                buffer[cont_buffer][i][j] = background->get_sprite()[i][j]; 
    }

    std::stringstream ss;
    ss << "Assentos Livres: " << heli_charge << "          | " << "Combustivel: " << heli_fuel;
    for(int i = 0; i < ss.str().size(); i++)
        buffer[cont_buffer][3][i + 2] = ss.str()[i];
    // usos futuros
    swap_buffer();
    clear_buffer();
}

void Fase::clear_buffer()
{
    
    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 170; j++)
            buffer[cont_buffer][i][j] = ' ';
    }

}

void Fase::swap_buffer()
{
    if(cont_buffer)
    {
        cont_buffer = 0;
        current_buffer = 1;
    }
    else
    {
        cont_buffer = 1;
        current_buffer = 0;
    }
}
