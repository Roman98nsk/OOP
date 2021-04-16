#pragma once
#include "Figure.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Laticce :
        public Figure
{
private:
    RectangleShape line1, line2, line3, line4;
public:
    Laticce();
    void setAllParam(int x, int y, Color color, Color fon);
    void draw(RenderWindow& win);
};