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
        std::stack<State*>* states;
        sf::Vector2i mousePosition;
        std::map<std::string, int>* bindKeys;

    public:
        enum class state
        {
            MAINMENUSTATE,
            GAMESTATE
        };

        State::state stateClass;

        State(sf::RenderWindow* window, std::stack<State*>* states, std::map<std::string, int>* bindKeys, std::map<std::string, sf::Texture*>* textures);
        ~State();

        void updateMouse();
        virtual void update(bool mouseLeftPress);
        virtual void update(float deltaWheel, float delta);
        virtual void render();
};

#endif