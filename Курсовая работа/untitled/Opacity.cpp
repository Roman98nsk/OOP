#include "Opacity.h"

Opacity::Opacity()
{
}

void Opacity::setAllParam(int x, int y, Color color, Color fon)
{
    Figure::x = x;
    Figure::y = y;
    Figure::color = color;
    Figure::fon = fon;
    m_opacity.setPosition(x, y);
    m_opacity.setSize(Vector2f(40.f, 40.f));
    m_opacity.setFillColor(fon);
}

void Opacity::setPosition(int x, int y)
{
    Figure::x = x;
    Figure::y = y;
    m_opacity.setPosition(x, y);
}

Color Opacity::getColor()
{
    return color;
}

void Opacity::setColor(Color color)
{
    Figure::color = color;
    m_opacity.setFillColor(color);
}

void Opacity::draw(RenderWindow& win)
{
    win.draw(m_opacity);
}

Opacity::~Opacity()
{
}
