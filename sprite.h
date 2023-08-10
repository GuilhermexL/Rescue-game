#ifndef SPRITE
#define SPRITE

#include "sprite_base.h"
#include <vector>
#include <string>
#include <fstream>

class Sprite : public Sprite_base
{
    std::vector<std::string> sprite;
    std::string name;
public:
    Sprite(std::string const& );
    ~Sprite(){}

    std::vector<std::string> const& get_sprite() const override { return this->sprite; }; 

    void init() override;
    void update() override;
    void draw() override;

};

#endif //SPRITE
