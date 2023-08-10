#include <iostream>
#include "fase.h"
#include "sprite.h"

int main(int argc, char** argv)
{
    Sprite s("sprites/menu_hel.txt");
    Sprite w("sprites/win.txt");
    Sprite l("sprites/lose.txt");
    s.init();
    w.init();
    l.init();
    Fase fs;
    std::string input;
    
   int run;

    while(true)
    {
        for(auto o: s.get_sprite())
            std::cout << o << std::endl;
        std::cin >> input;
        run = fs.run();
        if (run == 1)
        {
            for(auto o: w.get_sprite())
        	std::cout << o << std::endl;	
        }
        else if (run == -1)
        {
            for(auto o: l.get_sprite())
            	std::cout << o << std::endl;
        }
        std::cin >> input;
    }

    return 0;
}
