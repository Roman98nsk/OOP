#include "Cross.h"

Cross::Cross()
{
}

void Cross::setAllParam(int x, int y, Color color, Color fon)
{
    m_cross1.setPosition(x + 20, y + 20);
    m_cross1.setSize(Vector2f(40.f, 10.f));
    m_cross1.setFillColor(color);
    m_cross1.setOrigin(20.f, 5.f);
    m_cross1.setRotation(45);


    m_cross2.setPosition(x + 20, y + 20);
    m_cross2.setSize(Vector2f(40.f, 10.f));
    m_cross2.setFillColor(color);
    m_cross2.setOrigin(20.f, 5.f);
    m_cross2.setRotation(-45);
}

void Cross::setPosition(int x, int y)
{
}

void Cross::draw(RenderWindow& win)
{
    win.draw(m_cross1);
    win.draw(m_cross2);
}

