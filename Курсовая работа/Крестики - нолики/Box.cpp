#include "Box.h"

Box::Box() : m_x{ 0 }, m_y{ 0 }, m_type{ Box::DEFAULT }, m_anim{ 0 }
{
}

Box::Box(int x, int y, Box::Type type) : m_x{ x }, m_y{ y }, m_type{ type }, m_anim{ 0 }
{
    Color fon(206, 230, 242, 0);
    Color color(52, 52, 40);
    Color coloro(255, 203, 219);

    //circle
    zero.setAllParam(x, y, color, fon);

    //cross
    cross.setAllParam(x, y, color, fon);

    //opacity
    opacity.setAllParam(x, y, coloro, fon);
}

Box::Type Box::getType() const {
    return m_type;
}

void Box::setType(Box::Type type)
{
    m_type = type;
}

void Box::setAnim()
{
    m_anim = 3;
}

void Box::restart()
{
    m_type = Box::DEFAULT;
    m_anim = 0;
}

bool Box::isMouseClick(Vector2i pos)
{
    return (pos.x > m_x && pos.x < (m_x + 40) && pos.y > m_y && pos.y < (m_y + 40));
}

void Box::draw(RenderWindow& win)
{
    if (m_type == Box::ZERO) {
        zero.draw(win);
    }
    else if (m_type == Box::CROSS) {
        cross.draw(win);
    }

    if (m_anim > 1) {
        Color color = opacity.getColor();
        if (color.a <= 0) {
            m_anim--;
            color.a = 255;
        }
        color.a -= 8;
        opacity.setColor(color);
        opacity.draw(win);
    }

}

Box::~Box()
{
}
