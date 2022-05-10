#include "gameState.h"

GameState::GameState(sf::RenderWindow* window, std::map<std::string, bool>* pressedKeys, std::stack<State*>* states, std::map<std::string, sf::Texture*>* textures)
    : State(window, pressedKeys, states, textures)
{

}

GameState::~GameState()
{

}

void GameState::update()
{
    this->mousePosition;
}

void GameState::render()
{
    
}