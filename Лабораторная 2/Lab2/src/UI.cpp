#include "UI.h"
#include "gfx.h"
#include "point.h"
#include <cmath>
#include <time.h>

void show_screen(Point* points){
    gfx_open( XSCREEN, YSCREEN, "Points" );
    struct timespec tw = {0,50000000};
    struct timespec tr;
    nanosleep (&tw, &tr);
    char c = '0';
    while(c != 'q'){
        gfx_clear();
        for(int i = 0; i < COUNT; i++){
            if(c == 'r')
                points[i].random_move();
            if(c == 'l')
                points[i].line_move();
            create_point(points[i]);
        }
        if(gfx_event_waiting() == 1)
            c = gfx_wait();
        nanosleep (&tw, &tr);
    }
}

void create_point(Point point){
    gfx_color(rand()%256,rand()%256,rand()%256);
    gfx_point(point.get_x(),point.get_y());
}