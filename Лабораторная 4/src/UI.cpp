#include "UI.h"
#include "gfx.h"
#include "figure.h"
#include <cmath>
#include <time.h>

void draw_figures(Line** figures, char c){
    for(int i = 0; i < 6; i++){
        switch(c){
            case 's':figures[i]->spin();
            case 'l':figures[i]->line_move();
        }
        figures[i]->draw_figure();
    }
}

void show_screen(Line** figures){
    gfx_open( XSCREEN, YSCREEN, "Points" );
    struct timespec tw = {0,70000000};
    struct timespec tr;
    nanosleep (&tw, &tr);
    char c = '0';
    while(c != 'q'){
        gfx_clear();
        for(int i = 0; i < COUNT; i++){
            draw_figures(figures, c);
        }
        if(gfx_event_waiting() == 1)
            c = gfx_wait();
        nanosleep (&tw, &tr);
    }
}