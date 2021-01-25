#ifndef POINT_H
#define POINT_H

#define COUNT 100
#define SPEED 5

class Point{
    private:
    int x;
    int y;
    double direction;
    
    public:
    Point();
    void set_x(int px);
    void set_y(int py);
    int get_x();
    int get_y();
    void check_x();
    void check_y();
    void set_direction(float dir);
    void random_move();
    void line_move();
    double get_direction();
};

#endif