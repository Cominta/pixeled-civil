#include "tile.h"

Tile::Tile(sf::RenderWindow* window, sf::Texture* texture, float x, float y, float scale)
    : window(window), textureDefault(texture), x(x), y(y), scale(scale)
{
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(*this->textureDefault);
    this->sprite->setPosition(x, y);
    this->sprite->setScale(sf::Vector2f(scale, scale));
    // this->sprite->setOrigin(this->sprite->getTexture()->getSize().x / 2, this->sprite->getTexture()->getSize().y / 2);
    this->tileClass = Tile::tClass::GRASS;
}

Tile::~Tile()
{

}

void Tile::update()
{

}

void Tile::render()
{
    this->window->draw(*this->sprite);
}