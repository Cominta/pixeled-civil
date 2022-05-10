#include "mainMenuState.h"

MainState::MainState(sf::RenderWindow* window, std::map<std::string, bool>* pressedKeys, std::stack<State*>* states, std::map<std::string, sf::Texture*>* textures)
    : State(window, pressedKeys, states, textures)
{
    this->buttons["play-button"] = new Button(this->window, Button::bClass::PLAY, 200, 100, 0.1f, this->textures->at("main-play-button"));
}

MainState::~MainState()
{

}

void MainState::update()
{
    this->updateMouse();

    for (auto &button : this->buttons)
    {
        button.second->update(this->mousePosition, this->pressedKeys->at("mouse-left"));

        if (button.second->state == Button::states::ACTIVE && button.second->buttonClass == Button::bClass::PLAY)
        {
            this->states->push(new GameState(this->window, this->pressedKeys, this->states, this->textures));
        }
    }
}

void MainState::render()
{
    this->buttons["play-button"]->render();
}