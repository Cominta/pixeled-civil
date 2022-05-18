#include "gameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, std::map<std::string, int>* bindKeys, std::map<std::string, sf::Texture*>* textures)
    : State(window, states, bindKeys, textures)
{
    this->stateClass = State::state::GAMESTATE;
    this->buildMenuToogle = false;
    this->build = false;

    this->tilemap = new TileMap(this->window, 100, 100, this->textures);
    this->camera = new Camera(this->window, this->bindKeys);

    // this->view = new sf::View(sf::FloatRect(0, 0, this->window->getSize().x, this->window->getSize().y));
    // this->view->setCenter(0, 0);

    this->buttons["build-button"] = new Button(this->window, Button::bClass::BUILD, 0.0f, 0.0f, 1.0f, this->textures->at("build-button"));
    this->buildMenu = new DropDownBuildMenu(this->window, 430.0f, 220.0f, 10.0f, 92.0f); // 2 line, 6 items
    this->buildMenu->addItem("path", this->textures->at("path-level-1"));
    this->buildMenu->addItem("path", this->textures->at("path-level-1"));
    this->buildMenu->addItem("path", this->textures->at("path-level-1"));
    this->buildMenu->addItem("path", this->textures->at("path-level-1"));
    this->buildMenu->addItem("path", this->textures->at("path-level-1"));
    this->buildMenu->addItem("path", this->textures->at("path-level-1"));
    this->buildMenu->addItem("path", this->textures->at("path-level-1"));

    this->buildComponent = new BuildComponent(this->tilemap);
}

GameState::~GameState()
{

}

void GameState::update(float deltaWheel, float delta, bool mouseLeftPress)
{
    this->updateMouse();
    this->camera->update(delta, deltaWheel);

    float scaleX = this->window->getView().getSize().x / this->camera->scaleFactor / 18.0f;
    float scaleY = this->window->getView().getSize().y / this->camera->scaleFactor / 10;

    sf::Vector2f pos = this->window->mapPixelToCoords(sf::Vector2i(10, 10));
    this->buttons["build-button"]->setPosition(pos.x, pos.y);
    this->buttons["build-button"]->setScale(scaleX, scaleY);
    this->buttons["build-button"]->update(this->mousePosition, mouseLeftPress);

    if (this->buttons["build-button"]->state == Button::states::ACTIVE)
    {
        this->buildMenuToogle = !this->buildMenuToogle;
    }

    if (this->buildMenuToogle)
    {
        DropDownBuildMenu::Item* activeItem = this->buildMenu->update(scaleX, scaleY, this->mousePosition, mouseLeftPress);

        if (activeItem)
        {
            Building* building;

            if (activeItem->name == "path")
            {
                building = new Path(this->textures->at("path-level-1"), Tile::tClass::PATH);
            }

            mouseLeftPress = false;
            this->buildComponent->build(building);
        }

        this->buildComponent->update(this->mousePosition, mouseLeftPress);
    }
}

void GameState::render()
{
    this->tilemap->render();
    this->buttons["build-button"]->render();

    if (this->buildMenuToogle)
    {
        this->buildMenu->render();
    }
}