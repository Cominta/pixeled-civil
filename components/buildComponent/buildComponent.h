#ifndef BUILDCOMPONENT_H
#define BUILDCOMPONENT_H

#include <SFML/Graphics.hpp>
#include "../../entity/buildings/path.h"
#include "../tilemap/tilemap.h"

class BuildComponent 
{
    private:
        std::vector<Building*> buildings;
        TileMap* tilemap;

        bool buildState;
        Tile* lastTile;

    public:
        BuildComponent(TileMap* tilemap);
        ~BuildComponent();

        bool build(Building* building);

        void update(sf::Vector2f mousePosition, bool mouseLeftPress);
        void render();
};

#endif