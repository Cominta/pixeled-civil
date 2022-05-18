#ifndef PATH_H
#define PATH_H

#include "building.h"

class Path : public Building
{
    private:
        int level;

        float x;
        float y;

    public:
        Path(sf::Texture* texture, Tile::tClass tileClass);
        ~Path();

        void update();
};

#endif