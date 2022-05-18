#include "buildComponent.h"

BuildComponent::BuildComponent(TileMap* tilemap)
    : tilemap(tilemap)
{
    this->buildState = false;
}

BuildComponent::~BuildComponent()
{

}

bool BuildComponent::build(Building* building)
{
    this->buildState = true;

    this->buildings.emplace_back(building);
}

void BuildComponent::update(sf::Vector2f mousePosition, bool mouseLeftPress)
{
    if (this->buildState)
    {
        if (this->lastTile)
        {
            this->lastTile->setTextureDefault();
        }

        Tile* activeTile = this->tilemap->intersect(mousePosition);

        if (activeTile->tileClass == Tile::tClass::GRASS)
        {
            activeTile->setTexture(this->buildings[this->buildings.size() - 1]->getTexture());
            activeTile->tileClass = this->buildings[this->buildings.size() - 1]->tileClass;

            this->lastTile = activeTile;

            if (mouseLeftPress)
            {
                this->buildState = false;
                this->lastTile = nullptr;
            }
        }
    }
}

void BuildComponent::render()
{

}