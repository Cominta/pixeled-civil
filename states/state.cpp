#include "state.h"

State::State(sf::RenderWindow* window, std::map<std::string, bool>* pressedKeys, std::stack<State*>* states, std::map<std::string, sf::Texture*>* textures)
    : window(window), pressedKeys(pressedKeys), states(states), textures(textures)
{

}

State::~State()
{

}

void State::updateMouse()
{   
    this->mousePosition = this->window->mapPixelToCoords(sf::Mouse::getPosition(*(this->window)));
}

void State::update()
{

}

void State::render()
{

}