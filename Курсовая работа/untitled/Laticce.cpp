#include "Laticce.h"

Laticce::Laticce()
{
    Color color(52, 52, 40);
    Figure::color = color;

    line1.setSize(Vector2f(3.f, 160.f));
    x = 119.f; y = 20.f;
    line1.setPosition(Vector2f(x , y));
    line1.setFillColor(color);

    line2.setSize(Vector2f(3.f, 160.f));
    x = 178.f ; y = 20.f ;
    line2.setPosition(Vector2f(x, y));
    line2.setFillColor(color);

    line3.setSize(Vector2f(160.f, 3.f));
    x = 70.f; y = 69.f;
    line3.setPosition(Vector2f(x, y));
    line3.setFillColor(color);

    line4.setSize(Vector2f(160.f, 3.f));
    x = 70.f; y = 128.f;
    line4.setPosition(Vector2f(x, y));
    line4.setFillColor(color);
}

void Laticce::setAllParam(int x, int y, Color color, Color fon)
{
    Figure::x = x;
    Figure::y = y;
    Figure::color = color;
    Figure::fon = fon;
}

void Laticce::draw(RenderWindow& win)
{
    win.draw(line1);
    win.draw(line2);
    win.draw(line3);
    win.draw(line4);
}

