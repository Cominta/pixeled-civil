#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "../components/tilemap/tilemap.h"

class GameState : public State
{
    private:
        TileMap* tilemap;

    public:
        GameState(sf::RenderWindow* window, std::map<std::string, bool>* pressedKeys, std::stack<State*>* states, std::map<std::string, sf::Texture*>* textures);
        ~GameState();

        void update();
        void render();
};

#endif