#ifndef BUILDING_H
#define BUILDING_H

#include <SFML/Graphics.hpp>
#include "../../components/tilemap/tile.h"

class Building 
{
    protected:
        sf::Texture* texture;

    public:
        Tile::tClass tileClass;

        Building(sf::Texture* texture, Tile::tClass tileClass);
        ~Building();

        sf::Texture* getTexture() {return this->texture;};

        virtual void update();
        virtual void render();
};

#endif