#pragma once
#include <SFML/Graphics.hpp>
#include "Cross.h"
#include "Zero.h"
#include "Opacity.h"
using namespace sf;

class Box
{
public:
	enum Type
	{
		DEFAULT, CROSS, ZERO
	};

private:
	Type m_type;

	Cross cross;
	Zero zero;
	Opacity opacity;

	int m_x, m_y, m_anim;

public:
	Box();
	Box(int x, int y, Box::Type type = Box::DEFAULT);
	Box::Type getType() const;
	void setType(Box::Type type);
	void setAnim();
	void restart();

	bool isMouseClick(Vector2i pos);

	void draw(RenderWindow& win);
	~Box();
};

