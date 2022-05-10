#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <map>
#include <stack>

class State
{
    protected:
        sf::RenderWindow* window;
        std::map<std::string, sf::Texture*>* textures;
        std::map<std::string, bool>* pressedKeys;
        std::stack<State*>* states;
        sf::Vector2f mousePosition;

    public:
        State(sf::RenderWindow* window, std::map<std::string, bool>* pressedKeys, std::stack<State*>* states, std::map<std::string, sf::Texture*>* textures);
        ~State();

        void updateMouse();
        virtual void update();
        virtual void render();
};

#endif