#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

void init_terminal() {
    // initialize ncurses
    initscr();

    // turn off input buffering and echo mode
    cbreak();
    noecho();


}
