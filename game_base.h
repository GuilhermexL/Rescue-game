#ifndef GAME_BASE
#define GAME_BASE

class Game_base
{
    public:
        virtual void init() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
};

#endif //GAME_BASE
