#ifndef ENGINE_H
#define ENGINE_H

#include "states/mainMenuState.h"

class Engine
{
    private:
        sf::RenderWindow* window;
        sf::Event sfEvent;
        std::stack<State*> states;
        std::map<std::string, bool> pressedKeys;
        std::map<std::string, sf::Texture*> textures;
        
        void loadTextures();
        void initKeys();

    public:
        Engine();
        ~Engine();

        void start();

        void updateSFML();
        void update();
        void render();
};

#endif 