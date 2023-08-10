#ifndef SPRITE_ANIMADO
#define SPRITE_ANIMADO

#include "sprite_base.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Sprite_animado : public Sprite_base
{
    std::vector<std::string> sprite;
    std::string name;
    int cont_sprite = 1;
public:
    Sprite_animado(std::string const& );
    ~Sprite_animado(){}

    std::vector<std::string> const& get_sprite() const override { return this->sprite; }; 

    void init() override;
    void update() override;
    void draw() override;

};

#endif //SPRITE
