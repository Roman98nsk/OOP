#pragma once
#include "Figure.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Cross :
        public Figure
{
private:
    RectangleShape m_cross1;
    RectangleShape m_cross2;
public:
    Cross();
    void setAllParam(int x, int y, Color color, Color fon);
    void setPosition(int x, int y);
    void draw(RenderWindow& win);
};