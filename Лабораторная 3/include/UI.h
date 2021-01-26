#ifndef UI_H
#define UI_H
#include "figure.h"

#define YSCREEN 600
#define XSCREEN 800

void show_screen(Point* points,  Line* lines, Triangle* triangle, Rectangle* rectangle,Rhombus* rhombus,Circle* circle,Ellipse* ellipse);
void create_object(Point point);
void create_object(Line line);
void create_object(Triangle triangle);
void create_object(Rectangle rectangle);
void create_object(Rhombus rhombus);
void create_object(Circle circle);
void create_object(Ellipse ellipse);

#endif