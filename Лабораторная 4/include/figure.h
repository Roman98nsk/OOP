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
    virtual void draw_figure();
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
    void spin();
    double get_direction();
    void clear_deviation();
};

class Line{
    protected:
    Point* points;
    Point center;
    int count_points;
    double direction;

    public:
    Line();
    virtual void draw_figure();
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
    virtual void draw_figure();
};

class Rectangle: public Line{
    public:
    Rectangle();
    virtual void draw_figure();
};

class Rhombus: public Line{
    public:
    Rhombus();
    virtual void draw_figure();
};


class Circle: public Line{
    protected:
    double r;

    public:
    Circle();
    virtual void draw_figure();
    double get_r();
    void set_r(double new_r);
};

class Ellipse: public Circle{
    private:
    double k;
    public:
    Ellipse();
    virtual void draw_figure();
    double get_k();
    void set_k(double new_k);
};

#endif