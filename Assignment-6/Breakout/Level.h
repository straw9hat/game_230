#ifndef LEVEL_H
#define LEVEL_H

#include "Brick.h"

namespace gm {

    class Level
    {
    public:
        Brick* bricks[32] = {};
    protected:
        BrickType broken_brick = {
            1,
            sf::Color::White
        };

        BrickType normal_brick = {
            2,
            sf::Color::Red
        };
        
        int currentLevel;
        int bricksBroken;
        int totalBricks;
        int arr[3][4][8] =   {
            { {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1} },
            { {1, 2, 1, 2, 2, 1, 2, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 2, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 2, 2} },
            { {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1} }
        };
    public:
        Level();

        void update(sf::RenderWindow& window);

        void render(sf::RenderWindow& window);

        Brick* getBrick(int index);

        const int getCurrentLevel();

        const int getBricksBroken();
        
        const bool checkFinished();
        
        void setBricksBroken(int num);
        
        void setLevel(int l);
        
        void reset();

        ~Level();
    };
}

#endif