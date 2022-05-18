#ifndef DROPDOWNBUILDMENU_H
#define DROPDOWNBUILDMENU_H

#include <SFML/Graphics.hpp>
#include "button.h"
#include <vector>

class DropDownBuildMenu 
{
    public: 
        struct Item 
        {
            std::string name;
            sf::Text text;
            sf::Texture* icon;
            Button* button;
        };

    private:
        sf::RenderWindow* window;
        sf::RectangleShape* background;
        std::vector<std::vector<Item*>> grid;
        sf::Font font;

        int count;

        float width;
        float height;

        float x;
        float y;

    public:
        DropDownBuildMenu(sf::RenderWindow* window, float width, float height, float x, float y);
        ~DropDownBuildMenu();

        void addItem(std::string name, sf::Texture* icon);
        void setPosition(float x, float y) {this->background->setPosition(x, y);};
        void setScale(float scaleX, float scaleY) {this->background->setScale(scaleX, scaleY);};

        DropDownBuildMenu::Item* update(float scaleX, float scaleY, sf::Vector2f mousePosition, bool mouseLeftPress);
        void render();
};

#endif