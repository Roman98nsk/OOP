#pragma once
#include "Box.h"
#include "GameState.h"

class Menu 
{

private:
	Box menu_cross;
	Box menu_zero;
public:
	Menu();
	void setParam(GameState& game_state, Box::Type& user_box, RenderWindow& win);
	void draw(RenderWindow& win);
	~Menu();
};

