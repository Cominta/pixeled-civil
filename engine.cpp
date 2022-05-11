#include "engine.h"

Engine::Engine()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Pixeled civil", sf::Style::Default);

    this->loadTextures();
    this->initKeys();

    this->states.push(new MainState(this->window, &this->states, &this->bindKeys, &this->textures));
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

    std::ifstream keys;
    keys.open("config/gamestate-keys.ini");

    if (keys.is_open())
    {   
        std::string name;
        int key;

        while (keys >> name >> key)
        {
            this->bindKeys[name] = key;
        }
    }
}

void Engine::start()
{
    while (this->window->isOpen())
    {
        this->updateDelta();
        this->update();
        this->render();
    }
}

void Engine::updateDelta()
{
    this->delta = this->dtClock.restart().asSeconds();
}

void Engine::updateSFML()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
        {
            this->window->close();
        }

        if (this->sfEvent.mouseButton.button == sf::Mouse::Button::Left && this->sfEvent.type == sf::Event::MouseButtonReleased)
        {
            this->mouseLeftPress = true;
        }

        if (this->sfEvent.mouseWheelScroll.delta != 0)
        {
            this->deltaWheel = this->sfEvent.mouseWheelScroll.delta;
        }
    }
}

void Engine::update()
{
    this->updateSFML();

    if (!this->states.empty())
    {
        if (this->states.top()->stateClass == State::state::GAMESTATE)
        {
            this->states.top()->update(this->deltaWheel, this->delta);
        }
        
        else
        {
            this->states.top()->update(this->mouseLeftPress);
        }
    }

    this->deltaWheel = 0;
    this->mouseLeftPress = false;
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