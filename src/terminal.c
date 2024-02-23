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

void render_text(char *text, int x, int y) {
    // move the cursor to specified position
    move(y, x);

    // print the text at the current cursor
    printw("%s", text);

    // move cursor to the next line after printing 
    move(y + 1, 0);
} 


void update_cursor(int x, int y) {
    move(y, x);
} 

void clear_screen() {
    clear();
} 

void refresh_screen() {
    refresh();
} 
