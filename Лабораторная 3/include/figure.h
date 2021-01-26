#ifndef FIGURE_H
#define FIGURE_H

#define COUNT 2
#define SPEED 5
#define MAX_RADIUS 100

class Point{
    private:
    
    double deviation[2];
    protected:
    double x;
    double y;
    double direction;
    
    public:
    Point();
    void set_x(double px);
    void set_y(double py);
    double get_deviation_x();
    double get_deviation_y();
    double get_x();
    double get_y();
    double check_x();
    double check_y();
    void set_direction(double dir);
    void line_move();
    double get_direction();
    void clear_deviation();
};
//для адекватного лайн мув счётчик поинтов и по ним в цикле проходиться, чтобы можно было в наследование
class Line{
    protected:
    Point* points;
    Point center;
    int count_points;
    double direction;
    public:
    Line();
    void update_center();
    void set_point(Point new_point, int number);
    Point get_point(int number);
    void spin();
    void check_dir();
    void line_move();
    void balance_x(int number);
    void balance_y(int number);
    Point get_center();
};

class Triangle: public Line{
    public:
    Triangle();
};

class Rectangle: public Line{
    public:
    Rectangle();
};

class Rhombus: public Line{
    public:
    Rhombus();
};


class Circle: public Line{
    protected:
    double r;
    public:
    Circle();
    double get_r();
    void set_r(double new_r);
};

class Ellipse: public Circle{
    private:
    double k;
    public:
    Ellipse();
    double get_k();
    void set_k(double new_k);
};

#endif