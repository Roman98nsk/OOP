#pragma once
#include "Figure.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Opacity :
        public Figure
{
private:
    RectangleShape m_opacity;
public:
    Opacity();
    void setAllParam(int x, int y, Color color, Color fon);
    void setPosition(int x, int y);
    Color getColor();
    void setColor(Color color);
    void draw(RenderWindow& win);
    ~Opacity();
};
