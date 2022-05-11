#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Camera 
{
    private:
        sf::RenderWindow* window;
        std::map<std::string, int>* bindKeys;

        float currentSpeedX;
        float currentSpeedY;
        float speed;

    public:
        Camera(sf::RenderWindow* window, std::map<std::string, int>* bindKeys);
        ~Camera();

        void update(float delta);
};

#endif