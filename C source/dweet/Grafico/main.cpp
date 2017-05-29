#include <iostream>
#include <algorithm>
#include "../../vsgl2.h"

using namespace std;
using namespace vsgl2;
using namespace vsgl2::general;
using namespace vsgl2::video;
using namespace vsgl2::utils;
using namespace vsgl2::ttf_fonts;
int tempo;
void gitterClickDIBRUNO()
{
    draw_filled_rect(0,0,get_window_width(), get_window_height(), Color(24, 119, 242, 255));
    update();

    if(ms_time()-tempo>3000)
    {
        while(1)
        {
            draw_filled_rect(0,0,get_window_width(), get_window_height(), Color(113, 219, 96, 255));
            update();
        }
    }
}

int main(int argc, char* argv[]) {
    init();
    set_window(512,512,"Vsgl2 first example");
    tempo = ms_time();
    while(!done())
    {
            gitterClickDIBRUNO()
    }
    close();
    return 0;
}
