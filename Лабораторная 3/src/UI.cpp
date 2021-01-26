#include "UI.h"
#include "gfx.h"
#include "figure.h"
#include <cmath>
#include <time.h>

void show_screen(Point* points,Line* lines,Triangle* triangle,Rectangle* rectangle,Rhombus* rhombus,Circle* circle,Ellipse* ellipse){
    gfx_open( XSCREEN, YSCREEN, "Points" );
    struct timespec tw = {0,70000000};
    struct timespec tr;
    nanosleep (&tw, &tr);
    char c = '0';
    while(c != 'q'){
        gfx_clear();
        for(int i = 0; i < COUNT; i++){
            if(c == 's'){
                lines[i].spin();
                triangle[i].spin();
                rectangle[i].spin();
                rhombus[i].spin();
                ellipse[i].spin();
            }
            if (c == 'l'){
                points[i].line_move();
                lines[i].line_move();
                triangle[i].line_move();
                rectangle[i].line_move();
                rhombus[i].line_move();
                circle[i].line_move();
                ellipse[i].line_move();
            }
            create_object(points[i]);
            create_object(lines[i]);
            create_object(triangle[i]);
            create_object(rectangle[i]);
            create_object(rhombus[i]);
            create_object(circle[i]);
            create_object(ellipse[i]);
        }
        if(gfx_event_waiting() == 1)
            c = gfx_wait();
        nanosleep (&tw, &tr);
    }
}

void create_object(Point point){
    gfx_color(rand()%256,rand()%256,rand()%256);
    gfx_point(point.get_x(),point.get_y());
}

void create_object(Line line){
    gfx_color(rand()%256,rand()%256,rand()%256);
    gfx_line(line.get_point(0).get_x(),line.get_point(0).get_y(),line.get_point(1).get_x(),line.get_point(1).get_y());
}

void create_object(Triangle triangle){
    gfx_color(rand()%256,rand()%256,rand()%256);
    gfx_line(triangle.get_point(0).get_x(),triangle.get_point(0).get_y(),triangle.get_point(1).get_x(),triangle.get_point(1).get_y());
    gfx_line(triangle.get_point(1).get_x(),triangle.get_point(1).get_y(),triangle.get_point(2).get_x(),triangle.get_point(2).get_y());
    gfx_line(triangle.get_point(2).get_x(),triangle.get_point(2).get_y(),triangle.get_point(0).get_x(),triangle.get_point(0).get_y());
}

void create_object(Rectangle rectangle){
    gfx_color(rand()%256,rand()%256,rand()%256);
    gfx_line(rectangle.get_point(0).get_x(),rectangle.get_point(0).get_y(),rectangle.get_point(1).get_x(),rectangle.get_point(1).get_y());
    gfx_line(rectangle.get_point(1).get_x(),rectangle.get_point(1).get_y(),rectangle.get_point(2).get_x(),rectangle.get_point(2).get_y());
    gfx_line(rectangle.get_point(2).get_x(),rectangle.get_point(2).get_y(),rectangle.get_point(3).get_x(),rectangle.get_point(3).get_y());
    gfx_line(rectangle.get_point(3).get_x(),rectangle.get_point(3).get_y(),rectangle.get_point(0).get_x(),rectangle.get_point(0).get_y());
}

void create_object(Rhombus rhombus){
    gfx_color(rand()%256,rand()%256,rand()%256);
    gfx_line(rhombus.get_point(0).get_x(),rhombus.get_point(0).get_y(),rhombus.get_point(1).get_x(),rhombus.get_point(1).get_y());
    gfx_line(rhombus.get_point(1).get_x(),rhombus.get_point(1).get_y(),rhombus.get_point(2).get_x(),rhombus.get_point(2).get_y());
    gfx_line(rhombus.get_point(2).get_x(),rhombus.get_point(2).get_y(),rhombus.get_point(3).get_x(),rhombus.get_point(3).get_y());
    gfx_line(rhombus.get_point(3).get_x(),rhombus.get_point(3).get_y(),rhombus.get_point(0).get_x(),rhombus.get_point(0).get_y());
}

void create_object(Circle circle){
    gfx_color(rand()%256,rand()%256,rand()%256);
    float a = (M_PI / 180);
    int j = 1;
    for(float i = a; i < 2*M_PI; j++, i = a * j){
        gfx_point((cos(i)* circle.get_r()) + circle.get_center().get_x(),(sin(i)* circle.get_r()) + circle.get_center().get_y());
    }
}

void create_object(Ellipse ellipse){
    gfx_color(rand()%256,rand()%256,rand()%256);
    for(int i = 0; i < 359; i++){
        gfx_point(ellipse.get_point(i).get_x(),ellipse.get_point(i).get_y());
    }
}