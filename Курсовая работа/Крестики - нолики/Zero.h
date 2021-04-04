#pragma once
#include "Figure.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Zero :
	public Figure
{
private:
	CircleShape m_zero;
public:
	Zero();
	void setAllParam(int x, int y, Color color, Color fon);
	void setPosition(int x, int y);
	void draw(RenderWindow& win);
	~Zero();
};

