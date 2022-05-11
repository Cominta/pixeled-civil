#include "gameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, std::map<std::string, int>* bindKeys, std::map<std::string, sf::Texture*>* textures)
    : State(window, states, bindKeys, textures)
{
    this->stateClass = State::state::GAMESTATE;
    this->currentZoom = 1.0f;

    this->tilemap = new TileMap(this->window, 100, 100, this->textures);
    this->camera = new Camera(this->window, this->bindKeys);

    // this->view = new sf::View(sf::FloatRect(0, 0, this->window->getSize().x, this->window->getSize().y));
    // this->view->setCenter(0, 0);
}

GameState::~GameState()
{

}

void GameState::update(float deltaWheel, float delta)
{
    this->updateMouse();
    this->camera->update(delta);
}

void GameState::render()
{
    this->tilemap->render();
}