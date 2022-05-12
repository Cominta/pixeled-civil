#include "button.h"

Button::Button(sf::RenderWindow* window, Button::bClass buttonClass, float x, float y, float scale, sf::Texture* idle, sf::Texture* hover, sf::Texture* active)
    : window(window), buttonClass(buttonClass), x(x), y(y), scale(scale)
{
    this->setTexture(idle, hover, active);

    this->sprite = new sf::Sprite();
    this->sprite->setTexture(*this->idle);
    this->sprite->setPosition(this->x, this->y);
    this->sprite->setScale(this->scale, this->scale);
    this->sprite->setOrigin(this->sprite->getTexture()->getSize().x / 2, this->sprite->getTexture()->getSize().y / 2);

    this->state = Button::states::IDLE;
}

Button::~Button()
{

}

bool Button::isHover(sf::Vector2i mousePosition)
{
    if (this->sprite->getGlobalBounds().contains(mousePosition.x, mousePosition.y))
    {
        return true;
    }

    return false;
}

void Button::setTexture(sf::Texture* idle, sf::Texture* hover, sf::Texture* active)
{
    this->idle = idle;
    this->hover = hover;
    this->active = active;
}

void Button::setPosition(float x, float y)
{
    this->sprite->setPosition(x, y);
}

void Button::update(sf::Vector2i mousePosition, bool mousePressed)
{
    if (this->isHover(mousePosition))
    {
        if (mousePressed)
        {
            this->state = Button::states::ACTIVE;
        }

        else
        {
            this->state = Button::states::HOVER;
        }
    }

    else
    {
        this->state = Button::states::IDLE;
    }
}

void Button::render()
{
    this->window->draw(*this->sprite);
}