#include "engine.h"

Engine::Engine()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Pixeled civil", sf::Style::Fullscreen);

    this->loadTextures();
    this->initKeys();

    this->states.push(new MainState(this->window, &this->pressedKeys, &this->states, &this->textures));
}

Engine::~Engine()
{

}

void Engine::loadTextures()
{
    std::vector<std::string> names = {
        "main-play-button",
        "grass"
    };

    std::vector<std::string> paths = {
        "resources/main-menu-ui/buttons/play-button.png",
        "resources/tiles/grass.png"
    };

    for (int i = 0; i < names.size(); i++)
    {
        this->textures[names[i]] = new sf::Texture();
        this->textures[names[i]]->loadFromFile(paths[i]);
    }
}

void Engine::initKeys()
{
    this->pressedKeys["mouse-left"] = false;
}

void Engine::start()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

void Engine::updateSFML()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
        {
            this->window->close();
        }

        if (this->sfEvent.mouseButton.button == sf::Mouse::Left)
        {
            this->pressedKeys["mouse-left"] = true;
        }
    }
}

void Engine::update()
{
    this->updateSFML();

    if (!this->states.empty())
    {
        this->states.top()->update();
    }

    for (auto &pair : this->pressedKeys)
    {
        pair.second = false;
    }
}

void Engine::render()
{
    this->window->clear();

    if (!this->states.empty())
    {
        this->states.top()->render();
    }

    this->window->display();
}