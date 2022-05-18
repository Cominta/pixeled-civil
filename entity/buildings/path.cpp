#include "path.h"

Path::Path(sf::Texture* texture, Tile::tClass tileClass)
    : Building(texture, tileClass) 
{
    this->level = 1;
}

Path::~Path()
{

}

void Path::update()
{

}