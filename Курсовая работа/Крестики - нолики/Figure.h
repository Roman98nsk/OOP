#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Figure
{
protected:
	int x, y;
	Color color, fon;
public:
	Figure() : x{ 0 }, y{ 0 } { }
	Figure(int x, int y) : x{ x }, y{ y } { }
	Figure(int x, int y, Color color, Color fon) : x{ x }, y{ y }, color{ color }, fon{ fon } { }
	Figure(Color color, Color fon) :x{ 0 }, y{ 0 }, color{ color }, fon{ fon } { }
	virtual void setAllParam(int x, int y, Color color, Color fon) = 0;
	~Figure();
};

