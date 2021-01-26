#include <iostream>
#include "figure.h"
#include "UI.h"
#include "gfx.h"
#include <cmath>

using namespace std;

int main(){
    Triangle* triangle = new Triangle[COUNT];
    Point* point = new Point[COUNT];
    Line* line = new Line[COUNT];
    Rectangle* rectangles = new Rectangle[COUNT];
    Rhombus* rhombus = new Rhombus[COUNT];
    Circle* circle = new Circle[COUNT];
    Ellipse* ellipse = new Ellipse[COUNT];
    show_screen(point,line,triangle,rectangles,rhombus,circle,ellipse);
    return 0;
}