#include "camera.h"

Camera::Camera(sf::RenderWindow* window, std::map<std::string, int>* bindKeys)
    : window(window), bindKeys(bindKeys)
{
    this->currentSpeedX = 0;
    this->currentSpeedY = 0;
    this->speed = 400.0f;
    this->scaleFactor = 100;
}

Camera::~Camera()
{

}

void Camera::update(float delta, float deltaWheel)
{
    sf::View view {this->window->getView()};

    if (deltaWheel > 0)
    {
        // view.setSize(view.getSize().x - this->scaleFactor, view.getSize().y - this->scaleFactor);
        view.zoom(0.9f);
    }

    else if (deltaWheel < 0)
    {
        // view.setSize(view.getSize().x + this->scaleFactor, view.getSize().y + this->scaleFactor);
        view.zoom(1.101f);
    }


    float moveFast = 0.0f;

    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->bindKeys->at("camera-move-fast")))
    {
        moveFast = 300.0f;
    }

    this->currentSpeedX = 0;
    this->currentSpeedY = 0;

    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->bindKeys->at("camera-move-left")))
    {
        this->currentSpeedX = (-this->speed - moveFast) * delta;
    }

    else if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->bindKeys->at("camera-move-right")))
    { 
        this->currentSpeedX = (this->speed + moveFast) * delta;
    }

    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->bindKeys->at("camera-move-bottom")))
    {
        this->currentSpeedY = (this->speed + moveFast) * delta;
    }

    else if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->bindKeys->at("camera-move-top")))
    {
        this->currentSpeedY = (-this->speed - moveFast) * delta;
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