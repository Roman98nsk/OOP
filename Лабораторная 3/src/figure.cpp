#include "figure.h"
#include <cmath>
#include "UI.h"

Point::Point(){
    x = rand() % XSCREEN;
    y = rand() % YSCREEN;
    direction = fmod(float(rand()),2*M_PI);
}

double Point::get_x(){
    return x;
}

double Point::get_y(){
    return y;
}

void Point::set_x(double px){
    x = px;
}

void Point::set_y(double py){
    y = py;
}

void Point::set_direction(double dir){
    direction = dir;
}

void Point::line_move(){
    set_x(x + (cos(direction) * SPEED));
    set_y(y + (sin(direction) * SPEED));
    deviation[0] = check_x();
    deviation[1] = check_y();
}

double Point::check_x(){
    double r = 0;
    if (x <= 0 || x >= XSCREEN){
        if(direction < M_PI)
            set_direction(M_PI - direction);
        else
            set_direction((2*M_PI) - (direction - M_PI));
    }
    if(x < 0) {
        r = 0 - x;
        set_x(0);
    }
    if(x > XSCREEN) {
        r = XSCREEN - x;
        set_x(XSCREEN);
    }
    return r;   
}

double Point::check_y(){
    double r = 0;
    if (y <= 0){
        r = 0 - y;
        set_y(0);
        if(direction < M_PI * 0.5)
            set_direction(2 * M_PI - direction);
        else
            set_direction(M_PI + (M_PI - direction));
    }else if(y >= YSCREEN){
        r = YSCREEN - y;
        set_y(YSCREEN);
        if(direction < M_PI * 1.5)
            set_direction(M_PI - (direction - M_PI));
        else
            set_direction(2 * M_PI - direction);
    }
    return r;
}

double Point::get_direction(){
    return direction;
}

double Point::get_deviation_x(){
    return deviation[0];
}

double Point::get_deviation_y(){
    return deviation[1];
}

void Point::clear_deviation(){
    deviation[0] = 0;
    deviation[1] = 0;
}

Line::Line(){
    count_points = 2;
    direction = fmod(float(rand()),2*M_PI);
    points = new Point[count_points];
    update_center();
}

void Line::set_point(Point new_point, int number){
    points[number] = new_point;
    update_center();
}

void Line::update_center(){
    int sum_x = 0,sum_y = 0;
    for(int i = 0; i < count_points; i++){
        sum_x += points[i].get_x();
        sum_y += points[i].get_y();
    }
    center.set_x(sum_x/count_points);
    center.set_y(sum_y/count_points);
}

Point Line::get_point(int number){
    return points[number];
}

void Line::spin(){
    double a = (M_PI / 180) * SPEED;
    for(int i = 0; i < count_points; i++){
        points[i].set_x(center.get_x() + (points[i].get_x() - center.get_x()) * cos(a) - (points[i].get_y() - center.get_y())* sin(a));
        points[i].set_y(center.get_y() + (points[i].get_y() - center.get_y()) * cos(a) + (points[i].get_x() - center.get_x())* sin(a));
    }
}

void Line::line_move(){
    for(int i = 0; i < count_points; i++){
        points[i].set_direction(direction);
        points[i].line_move();
        if(points[i].get_deviation_x() != 0){
            balance_x(i);
        }
        if(points[i].get_deviation_y() != 0){
            balance_y(i);
        }
        points[i].clear_deviation();
    }
    update_center();
    check_dir();
}

void Line::check_dir(){
    for(int i = 0; i < count_points; i++){
        if (points[i].get_direction() != direction){
            direction = points[i].get_direction();
            for(int j = 0; j < count_points; j++){
                points[j].set_direction(points[i].get_direction());
            }
        } 
    }
}

void Line::balance_x(int number){
    for(int i = 0 ; i < count_points; i++){
        if(i != number){
            points[i].set_x(points[i].get_x() + points[number].get_deviation_x());
        }
    }
}

void Line::balance_y(int number){
    for(int i = 0 ; i < count_points; i++){
        if(i != number){
            points[i].set_y(points[i].get_y() + points[number].get_deviation_y());
        }
    }
}

Point Line::get_center(){
    return center;
}

Triangle::Triangle(){
    count_points = 3;
    direction = fmod(float(rand()),2*M_PI);
    points = new Point[count_points];
    update_center();
}

Rectangle::Rectangle(){
    count_points = 4;
    direction = fmod(float(rand()),2*M_PI);
    points = new Point[count_points];
    points[1].set_x(points[0].get_x());
    points[1].set_y(points[2].get_y());
    points[3].set_x(points[2].get_x());
    points[3].set_y(points[0].get_y());
    update_center();
}

Rhombus::Rhombus(){
    count_points = 4;
    direction = fmod(float(rand()),2*M_PI);
    points = new Point[count_points];
    double x = points[0].get_x() - points[1].get_x();
    double y = points[0].get_y() - points[1].get_y();
    points[3].set_x(points[0].get_x() - x);
    points[3].set_y(points[0].get_y() + y);
    points[2].set_x(points[1].get_x() - x);
    points[2].set_y(points[1].get_y() + y);
    for(int i = 0; i < count_points; i++){
        points[i].set_x(points[i].get_x() / 2);
        points[i].set_y(points[i].get_y() / 2);
    }
    update_center();
}



Circle::Circle(){
    count_points = 4;
    points = new Point[count_points];
    direction = fmod(float(rand()),2*M_PI);
    r = rand() % MAX_RADIUS;
    points[0].set_x(center.get_x());
    points[0].set_y(center.get_y() + r);
    points[1].set_x(center.get_x());
    points[1].set_y(center.get_y() - r);
    points[2].set_x(center.get_x() + r);
    points[2].set_y(center.get_y());
    points[3].set_x(center.get_x()- r);
    points[3].set_y(center.get_y() );
}

double Circle::get_r(){
    return r;
}

void Circle::set_r(double new_r){
    r = new_r;
}

double Ellipse::get_k(){
    return k;
}

void Ellipse::set_k(double new_k){
    k = new_k;
}

Ellipse::Ellipse(){
    count_points = 359;
    points = new Point[count_points];
    direction = fmod(float(rand()),2*M_PI);
    r = rand() % MAX_RADIUS / 2;
    k = (rand() % int(r)) / 2;
    float a = (M_PI / 180);
    int j = 1;
    for(float i = a; i < 2*M_PI; j++, i = a * j){
        points[j - 1].set_x((cos(i)* r) + center.get_x());
        points[j - 1].set_y(sin(i)* (r - k) + center.get_y());
    }
    update_center();
}