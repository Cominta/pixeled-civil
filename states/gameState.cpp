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

    this->buttons["build-button"] = new Button(this->window, Button::bClass::BUILD, 0.0f, 0.0f, 1.0f, this->textures->at("build-button"));
}

GameState::~GameState()
{
    
}

void GameState::update(float deltaWheel, float delta, bool mouseLeftPress)
{
    this->updateMouse();
    this->camera->update(delta, deltaWheel);

    sf::Vector2f pos = this->window->mapPixelToCoords(sf::Vector2i(50, 50));
    this->buttons["build-button"]->setPosition(pos.x, pos.y);
    this->buttons["build-button"]->setScale(this->window->getView().getSize().x / this->camera->scaleFactor / 10, this->window->getView().getSize().y / this->camera->scaleFactor / 10);
}

void GameState::render()
{
    this->tilemap->render();
    this->buttons["build-button"]->render();
}