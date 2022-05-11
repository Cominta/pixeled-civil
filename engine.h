#ifndef ENGINE_H
#define ENGINE_H

#include "states/mainMenuState.h"
#include <fstream>

class Engine
{
    private:
        sf::RenderWindow* window;
        sf::Event sfEvent;
        std::stack<State*> states;

        std::map<std::string, int> bindKeys;
        bool mouseLeftPress;

        int deltaWheel;

        sf::Clock dtClock;
        float delta;

        std::map<std::string, sf::Texture*> textures;
        
        void loadTextures();
        void initKeys();

    public:
        Engine();
        ~Engine();

        void start();

        void updateDelta();
        void updateSFML();
        void update();
        void render();
};

#endif 