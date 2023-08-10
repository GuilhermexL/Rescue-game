#ifndef SPRITE_BASE
#define SPRITE_BASE

#include "game_base.h"
#include <vector>
#include <string>

class Sprite_base : public Game_base
{
public:
    virtual ~Sprite_base(){};

    virtual std::vector<std::string> const& get_sprite() const = 0; 

};


#endif //SPRITE_BASE
