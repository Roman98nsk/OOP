#include "Menu.h"
#include "Box.h"

Menu::Menu() : menu_zero{ 100, 80, Box::ZERO },
               menu_cross{ 160, 80, Box::CROSS }
{

}

void Menu::setParam(GameState& game_state, Box::Type& user_box, RenderWindow& win) {

    if (Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i pos = Mouse::getPosition(win);
        if (menu_cross.isMouseClick(pos)) {
            game_state = GameState::RUN;
            user_box = Box::CROSS;
        }
        else if (menu_zero.isMouseClick(pos)) {
            game_state = GameState::RUN;
            user_box = Box::ZERO;
        }
    }
}

void Menu::draw(RenderWindow& win) {
    menu_cross.draw(win);
    menu_zero.draw(win);
}

Menu::~Menu()
{
}

