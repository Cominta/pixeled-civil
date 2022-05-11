#include "mainMenuState.h"

MainState::MainState(sf::RenderWindow* window, std::stack<State*>* states, std::map<std::string, int>* bindKeys, std::map<std::string, sf::Texture*>* textures)
    : State(window, states, bindKeys, textures)
{
    this->stateClass = State::state::MAINMENUSTATE;

    this->buttons["play-button"] = new Button(this->window, Button::bClass::PLAY, 200, 100, 0.1f, this->textures->at("main-play-button"));
}

MainState::~MainState()
{

}

void MainState::update(bool mouseLeftPress)
{
    this->updateMouse();

    for (auto &button : this->buttons)
    {
        button.second->update(this->mousePosition, mouseLeftPress);

        if (button.second->state == Button::states::ACTIVE && button.second->buttonClass == Button::bClass::PLAY)
        {
            this->states->push(new GameState(this->window, this->states, this->bindKeys, this->textures));
        }
    }
}

void MainState::render()
{
    this->buttons["play-button"]->render();
}