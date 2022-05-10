#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Tile 
{
    private:
        sf::RenderWindow* window;
        sf::Sprite* sprite;
        sf::Texture* texture;

        float x;
        float y;
        float scale;

    public:
        Tile(sf::RenderWindow* window, sf::Texture* texture, float x, float y, float scale);
        ~Tile();

        void update();
        void render();
};

#endif