#include "../include/terminal.h"


#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h> // needed for cmock
#include <string.h>
#include <curses.h>
#include "/usr/local/Cellar/cmocka/1.1.7/include/cmocka.h"

// verify ncurses init and shutdown called
int init_called = 0;
int shutdown_called = 0;

void stub_init() {
    init_called = 1;
} 

void stub_shutdown() {
    shutdown_called = 1;
} 

// stub initscr
WINDOW* stub_initscr() {
    return NULL;
} 

// stub endwin
int stub_endwin() {
    return 0;
} 

int stub_get_key_press(void) {
    return (int)mock();
} 

int stub_getch(void);

void stub_render_text(char *text, int x, int y);
void stub_update_cursor(int x, int y);

int stub_mvprintw(int y, int x, const char *str);

int stub_move(int y, int x);

int stub_clear(void);

int stub_refresh(void);


// Test init and shutdown 
void test_init_shutdown() {
    will_return(stub_initscr, NULL);
    will_return(stub_endwin, OK);

    stub_init();
    assert_true(init_called);

    stub_shutdown();

    assert_true(shutdown_called);
}

// Declare variables to capture state
char text_buffer[256];
int cursor_x, cursor_y;

// function prototypes
void handle_key_press();
void update_text_buffer(char c);
void move_cursor(int x, int y);

void test_handle_key_press(void **state) {
    // reset text buffer and cursor position
    memset(text_buffer, 0, sizeof(text_buffer));

    // set up the stub for get_key_press 
    will_return(stub_get_key_press(), 'a');

    // call handle key press
    handle_key_press();
    // Add assertsion
    assert_string_equal(text_buffer, "a");

    // assert the cursor position was updated correctly
    assert_int_equal(cursor_x, 1);
    assert_int_equal(cursor_y, 0);
} 

void test_get_key_press(void **state) {
    will_return(stub_getch, 'b');

    int key_code = get_key_press();

    assert_int_equal(key_code, 'b');
} 

void test_render_ui(void **state) {
    will_return(stub_render_text, &stub_render_text);
    will_return(stub_update_cursor, &stub_update_cursor);

    render_ui();


    // Assertions
} 

void test_render_text(void **state) {
    will_return(stub_mvprintw, &stub_mvprintw);

    render_text("Hello, World!", 10, 5);


    // Add assertions
} 

void test_update_cursor(void **state) {
    will_return(stub_move, &stub_move);

    update_cursor(20, 10);

    // assertions
} 

void test_clear_screen(void **state) {
    will_return(stub_clear, &stub_clear);

    clear_screen();

    // Assertions
}

void test_refresh_screen(void **state) {
    will_return(stub_refresh, &stub_refresh);

    refresh_screen();

    // Assertions
}

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_init_shutdown),
        cmocka_unit_test(test_handle_key_press),
        cmocka_unit_test(test_get_key_press),
        cmocka_unit_test(test_render_ui),
        cmocka_unit_test(test_render_text),
        cmocka_unit_test(test_update_cursor),
        cmocka_unit_test(test_clear_screen),
        cmocka_unit_test(test_refresh_screen),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
} 

