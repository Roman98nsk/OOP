#include "point.h"
#include <cmath>
#include "UI.h"

Point::Point(){
    x = rand() % XSCREEN;
    y = rand() % YSCREEN;
    direction = fmod(float(rand()),2*M_PI);
}

int Point::get_x(){
    return x;
}

int Point::get_y(){
    return y;
}

void Point::set_x(int px){
    x = px;
}

void Point::set_y(int py){
    y = py;
}

void Point::set_direction(float dir){
    direction = dir;
}

void Point::line_move(){
    set_x(x + (cos(direction) * SPEED));
    set_y(y + (sin(direction) * SPEED));
    check_x();
    check_y();
}

void Point::random_move(){
    set_direction(fmod(float(rand()),2*M_PI));
    set_x(x + cos(direction) * SPEED);
    set_y(y + sin(direction) * SPEED);
    check_x();
    check_y();
}

void Point::check_x(){
    if (x <= 0 || x >= XSCREEN){
        if(direction < M_PI)
            set_direction(M_PI - direction);
        else
            set_direction((2*M_PI) - (direction - M_PI));
    }
    if(x < 0) set_x(0);
    if(x > XSCREEN) set_x(XSCREEN);
}

void Point::check_y(){
    if (y <= 0){
        set_y(0);
        if(direction < M_PI * 0.5)
            set_direction(2 * M_PI - direction);
        else
            set_direction(M_PI + (M_PI - direction));
    }else if(y >= YSCREEN){
        set_y(YSCREEN);
        if(direction < M_PI * 1.5)
            set_direction(M_PI - (direction - M_PI));
        else
            set_direction(2 * M_PI - direction);
    }
}