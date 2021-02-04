#include <iostream>
#include "figure.h"
#include "UI.h"
#include "gfx.h"
#include <cmath>

using namespace std;

int main(){
    Triangle triangle; 
    Line line; 
    Rectangle rectangles; 
    Rhombus rhombus; 
    Circle circle; 
    Ellipse ellipse; 
    Line* figures[] = {&line,&triangle,&rectangles,&rhombus,&circle,&ellipse}; 
    show_screen(figures);
    return 0;
}