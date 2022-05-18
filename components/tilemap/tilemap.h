#ifndef TILEMAP_H
#define TILEMAP_H

#include "tile.h"
#include <vector>
#include <map>

class TileMap
{
    private:
        sf::RenderWindow* window;
        std::vector<std::vector<Tile*>> tiles;
        std::map<std::string, sf::Texture*>* textures;

        int sizeX;
        int sizeY;

    public:
        TileMap(sf::RenderWindow* window, int sizeX, int sizeY, std::map<std::string, sf::Texture*>* textures);
        ~TileMap();

        Tile* intersect(sf::Vector2f mousePosition);

        void update();
        void render();
};

#endif