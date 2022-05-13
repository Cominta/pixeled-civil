#include "dropDownBuildMenu.h"

DropDownBuildMenu::DropDownBuildMenu(sf::RenderWindow* window, float width, float height, float x, float y)
    : window(window), width(width), height(height), x(x), y(y)
{
    this->background = new sf::RectangleShape(sf::Vector2f(this->width, this->height));
    this->background->setPosition(this->x, this->y);
    this->background->setFillColor(sf::Color(0, 0, 0, 128));

    this->font.loadFromFile("fonts/slkscr.ttf");

    for (int x = 0; x < 2; x++)
    {
        this->grid.emplace_back(std::vector<DropDownBuildMenu::Item*>());
        for (int y = 0; y < 6; y++)
        {
            this->grid.at(x).emplace_back(nullptr);
        }
    }
}

DropDownBuildMenu::~DropDownBuildMenu()
{

}

void DropDownBuildMenu::addItem(std::string name, sf::Texture* icon)
{
    bool find = false;

    for (int x = 0; x < this->grid.size(); x++)
    {
        for (int y = 0; y < this->grid.at(x).size(); y++)
        {
            if (this->grid.at(x).at(y) == nullptr)
            {
                DropDownBuildMenu::Item* newItem = new DropDownBuildMenu::Item();

                newItem->name = name;
                newItem->text = sf::Text(name, this->font, 15);
                newItem->icon = icon;
                newItem->button = new Button(this->window, Button::bClass::BUILD_ITEM, icon->getSize().x * y, icon->getSize().y * x, 1.0f, icon);

                this->grid.at(x).at(y) = newItem;

                find = true;
                break;
            }
        }

        if (find)
        {
            break;
        }
    }
}

void DropDownBuildMenu::update(float scaleX, float scaleY)
{
    sf::Vector2f pos = this->window->mapPixelToCoords(sf::Vector2i(10, 92));
    this->background->setPosition(pos.x, pos.y);
    this->background->setScale(scaleX, scaleY);

    int yMargin = 10;

    for (int x = 0; x < this->grid.size(); x++)
    {
        if (x > 0)
        {
            yMargin = this->grid.at(0).at(0)->text.getCharacterSize() + 20;
        }

        for (int y = 0; y < this->grid.at(x).size(); y++)
        {
            if (this->grid.at(x).at(y) != nullptr)
            {
                int xCoord = this->x + (10 * (y + 1)) + this->grid.at(x).at(y)->button->size * y;
                int yCoord = this->y + (yMargin * (x + 1)) + this->grid.at(x).at(y)->button->size * x;

                this->grid.at(x).at(y)->button->setScale(scaleX, scaleY);

                sf::Vector2f posButton = this->window->mapPixelToCoords(sf::Vector2i(xCoord, yCoord));

                this->grid.at(x).at(y)->button->setPosition(posButton); 


                sf::Vector2f posText = this->window->mapPixelToCoords(sf::Vector2i(xCoord, yCoord + this->grid.at(x).at(y)->button->size + 10));
                this->grid.at(x).at(y)->text.setScale(scaleX, scaleY);
                this->grid.at(x).at(y)->text.setPosition(posText.x, posText.y);

                // std::cout << this->grid.at(x).at(y)->button->getSize().x * scaleX  << "\n";
            }
        }
    }
}

void DropDownBuildMenu::render()
{
    this->window->draw(*this->background);

    for (auto &row : this->grid)
    {
        for (auto &item : row)
        {
            if (item != nullptr)
            {
                item->button->render();
                this->window->draw(item->text);
            }
        }
    }
}