#include "gameState.h"

GameState::GameState(sf::RenderWindow* window, std::map<std::string, bool>* pressedKeys, std::stack<State*>* states, std::map<std::string, sf::Texture*>* textures)
    : State(window, pressedKeys, states, textures)
{
    this->tilemap = new TileMap(this->window, 10, 10, this->textures);
}

GameState::~GameState()
{

}

void GameState::update()
{
    this->updateMouse();
}

void GameState::render()
{
    this->tilemap->render();
}