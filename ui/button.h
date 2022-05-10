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
            PLAY
        };

        Button::states state;
        Button::bClass buttonClass;

        Button(sf::RenderWindow* window, Button::bClass buttonClass, float x, float y, float scale, sf::Texture* idle, sf::Texture* hover = nullptr, sf::Texture* active = nullptr);
        ~Button();

        bool isHover(sf::Vector2f mousePosition);
        void setTexture(sf::Texture* idle, sf::Texture* hover, sf::Texture* active);

        void update(sf::Vector2f mousePosition, bool mousePressed);
        void render();
};

#endif