#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
    private:
        sf::RenderWindow* window;
        sf::Sprite* sprite;

        sf::Texture* idle;
        sf::Texture* hover;
        sf::Texture* active;

        float x;
        float y;
        float scale;

    public:
        enum class states
        {
            IDLE,
            HOVER,
            ACTIVE
        };

        enum class bClass
        {
            PLAY,
            BUILD
        };

        Button::states state;
        Button::bClass buttonClass;

        Button(sf::RenderWindow* window, Button::bClass buttonClass, float x, float y, float scale, sf::Texture* idle, sf::Texture* hover = nullptr, sf::Texture* active = nullptr);
        ~Button();

        bool isHover(sf::Vector2i mousePosition);
        void setTexture(sf::Texture* idle, sf::Texture* hover, sf::Texture* active);
        void setPosition(float x, float y) {this->sprite->setPosition(x, y);};
        void setScale(float scaleX, float scaleY) {this->sprite->setScale(scaleX, scaleY);};

        void update(sf::Vector2i mousePosition, bool mousePressed);
        void render();
};

#endif