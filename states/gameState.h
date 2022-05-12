#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "../components/tilemap/tilemap.h"
#include "../components/camera/camera.h"
#include "../ui/button.h"

class GameState : public State
{
    private:
        TileMap* tilemap;
        sf::View* view;
        Camera* camera;
        std::map<std::string, Button*> buttons;

        float currentZoom;

    public:
        GameState(sf::RenderWindow* window, std::stack<State*>* states, std::map<std::string, int>* bindKeys, std::map<std::string, sf::Texture*>* textures);
        ~GameState();

        void update(float deltaWheel, float delta, bool mouseLeftPress);
        void render();
};

#endif