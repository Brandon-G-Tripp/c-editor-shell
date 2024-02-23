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

void shutdown_terminal() {
    // Restore terminal to original state
    endwin();
}

int get_key_press() {
    // read char from terminal 
    int key = getch();

    // handle special keys
    switch (key) {
        case KEY_UP:
            return KEY_UP;
        case KEY_DOWN:
            return KEY_DOWN;
        case KEY_LEFT:
            return KEY_LEFT;
        case KEY_RIGHT:
            return KEY_RIGHT;
        default:
            return key;
    }
} 
