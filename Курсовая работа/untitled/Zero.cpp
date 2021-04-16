#include "Zero.h"

Zero::Zero()
{
}

void Zero::setAllParam(int x, int y, Color color, Color fon)
{
    m_zero.setPosition(x + 22, y + 22);
    m_zero.setRadius(12);
    m_zero.setOrigin(15.f, 15.f);
    m_zero.setFillColor(fon);
    m_zero.setOutlineColor(color);
    m_zero.setOutlineThickness(7);
}

void Zero::setPosition(int x, int y)
{
    m_zero.setPosition(x + 22, y + 22);
}

void Zero::draw(RenderWindow& win)
{
    win.draw(m_zero);
}

Zero::~Zero()
{
}

