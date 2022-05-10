#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "state.h"
#include "../ui/button.h"
#include "gameState.h"

class MainState : public State
{
    private:
        std::map<std::string, Button*> buttons;

    public:
        MainState(sf::RenderWindow* window, std::map<std::string, bool>* pressedKeys, std::stack<State*>* states, std::map<std::string, sf::Texture*>* textures);
        ~MainState();

        void update();
        void render();
};

#endif