#include "camera.h"

Camera::Camera(sf::RenderWindow* window, std::map<std::string, int>* bindKeys)
    : window(window), bindKeys(bindKeys)
{
    this->currentSpeedX = 0;
    this->currentSpeedY = 0;
    this->speed = 300.0f;
}

Camera::~Camera()
{

}

void Camera::update(float delta)
{
    sf::View view {this->window->getView()};

    bool move = false;
    this->currentSpeedX = 0;
    this->currentSpeedY = 0;

    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->bindKeys->at("camera-move-left")))
    {
        this->currentSpeedX = -this->speed * delta;
        move = true;
    }

    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->bindKeys->at("camera-move-right")))
    {
        this->currentSpeedX = this->speed * delta;
        move = true;
    }

    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->bindKeys->at("camera-move-bottom")))
    {
        this->currentSpeedY = this->speed * delta;
        move = true;
    }

    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->bindKeys->at("camera-move-top")))
    {
        this->currentSpeedY = -this->speed * delta;
        move = true;
    }

    // else if (!move)
    // {
    //     if (this->currentSpeedX < -3)
    //     {
    //         this->currentSpeedX += this->speed * delta;
    //     }

    //     else if (this->currentSpeedX > 3)
    //     {
    //         this->currentSpeedX -= this->speed * delta;
    //     }

    //     else 
    //     {
    //         this->currentSpeedX = 0;
    //     }

    //     if (this->currentSpeedY < -1)
    //     {
    //         this->currentSpeedY += this->speed * delta;
    //     }

    //     else if (this->currentSpeedY > 1)
    //     {
    //         this->currentSpeedY -= this->speed * delta;
    //     }

    //     else 
    //     {
    //         this->currentSpeedY = 0;
    //     }
    // }

    view.move(this->currentSpeedX, this->currentSpeedY);
    this->window->setView(view);
}