#include "state.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states, std::map<std::string, int>* bindKeys, std::map<std::string, sf::Texture*>* textures)
    : window(window), states(states), bindKeys(bindKeys), textures(textures)
{

}

State::~State()
{

}

void State::updateMouse()
{   
    // this->mousePosition = sf::Mouse::getPosition(*(this->window));
    this->mousePosition = this->window->mapPixelToCoords(sf::Mouse::getPosition(*(this->window)));
}

void State::update(bool mouseLeftPress)
{

}

void State::update(float deltaWheel, float delta, bool mouseLeftPress)
{

}

void State::render()
{

}