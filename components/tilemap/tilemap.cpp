#include "tilemap.h"

TileMap::TileMap(sf::RenderWindow* window, int sizeX, int sizeY, std::map<std::string, sf::Texture*>* textures)
    : window(window), sizeX(sizeX), sizeY(sizeY), textures(textures)
{
    float scale = 1.0f;

    for (int x = 0; x < this->sizeX; x++)
    {
        this->tiles.emplace_back(std::vector<Tile*>());
        for (int y = 0; y < this->sizeY; y++)
        {
            this->tiles.at(x).emplace_back(new Tile(this->window, this->textures->at("grass"), this->textures->at("grass")->getSize().x * x * scale, this->textures->at("grass")->getSize().y * y * scale, scale));
        }
    }
}

TileMap::~TileMap()
{

}

Tile* TileMap::intersect(sf::Vector2f mousePosition)
{
    for (auto &column : this->tiles)
    {
        for (auto &item : column)
        {
            if (item->getSprite()->getGlobalBounds().intersects(sf::FloatRect(mousePosition, sf::Vector2f(5, 5))))
            {
                return item;
            }
        }
    }
}

void TileMap::update()
{

}

void TileMap::render()
{
    for (int x = 0; x < this->sizeX; x++)
    {
        this->tiles.emplace_back(std::vector<Tile*>());
        for (int y = 0; y < this->sizeY; y++)
        {
            this->tiles.at(x).at(y)->render();
        }
    }
}