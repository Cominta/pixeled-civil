#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Tile 
{
    private:
        sf::RenderWindow* window;
        sf::Sprite* sprite;
        sf::Texture* textureDefault;
        sf::Texture* texture;

        float x;
        float y;
        float scale;


    public:
        enum class tClass 
        {
            GRASS,
            PATH
        };

        Tile::tClass tileClass; 
        
        Tile(sf::RenderWindow* window, sf::Texture* texture, float x, float y, float scale);
        ~Tile();

        void setTextureDefault() {this->sprite->setTexture(*this->textureDefault); this->tileClass = Tile::tClass::GRASS;};
        void setTexture(sf::Texture* texture) {this->texture = texture; this->sprite->setTexture(*this->texture);}
        sf::Sprite* getSprite() {return this->sprite;};

        void update();
        void render();
};

#endif