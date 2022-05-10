#include "button.h"

Button::Button(sf::RenderWindow* window, Button::bClass buttonClass, float x, float y, float scale, sf::Texture* idle, sf::Texture* hover, sf::Texture* active)
    : window(window), buttonClass(buttonClass), x(x), y(y), scale(scale)
{
    this->setTexture(idle, hover, active);

    this->shape = new sf::Sprite();
    this->shape->setTexture(*this->idle);
    this->shape->setPosition(this->x, this->y);
    this->shape->setScale(this->scale, this->scale);

    this->state = Button::states::IDLE;
}

Button::~Button()
{

}

bool Button::isHover(sf::Vector2f mousePosition)
{
    if (this->shape->getGlobalBounds().contains(mousePosition))
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

void Button::update(sf::Vector2f mousePosition, bool mousePressed)
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
    this->window->draw(*this->shape);
}