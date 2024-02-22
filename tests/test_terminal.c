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

int stub_render_text_x;
int stub_render_text_y;


void stub_render_text(char *text, int x, int y) {
    stub_render_text_x = x;
    stub_render_text_y = y;
}

int stub_update_cursor_x;
int stub_update_cursor_y;

void stub_update_cursor(int x, int y) {
    stub_update_cursor_x = x;
    stub_update_cursor_y = y;
}

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
    int key_code;

    // Test case: Normal key press
    will_return(stub_getch, 'b');
    key_code = get_key_press();
    assert_int_equal(key_code, 'b');

    // Test case: special key press (e.g., arrow key)
    will_return(stub_getch, KEY_UP);
    key_code = get_key_press();
    assert_int_equal(key_code, KEY_UP);


    // test case: function key press (e.g., F1,)
    will_return(stub_getch, KEY_F(1));
    key_code = get_key_press();
    assert_int_equal(key_code, KEY_F(1));

    // Test case: escape key press 
    will_return(stub_getch, 27);
    key_code = get_key_press();
    assert_int_equal(key_code, 27);


    // Test case: Null character
    will_return(stub_getch, ERR);
    key_code = get_key_press();
    assert_int_equal(key_code, ERR);
} 

void test_render_ui(void **state) {
    will_return(stub_render_text, &stub_render_text);
    will_return(stub_update_cursor, &stub_update_cursor);
    
    // Set up test data 
    strcpy(text_buffer, "Hello, World!");
    cursor_x = 5;
    cursor_y = 2;

    // Call the function under test
    render_ui();

    // verify that render_text function was called with correct args
    assert_true(stub_render_text == render_text);
    assert_string_equal(text_buffer, "Hello, World!");
    assert_int_equal(stub_render_text_x, 0); 
    assert_int_equal(stub_render_text_y, 0); 
   
    // Verify that the update_cursor function was called with correct args
    assert_true(stub_update_cursor == update_cursor);
    assert_int_equal(stub_update_cursor_x, cursor_x);
    assert_int_equal(stub_update_cursor_y, cursor_y);


} 

void test_render_text(void **state) {
    // Set up test data 
    char *text = "Hello, World!";
    int x = 5, y = 3;

    // Set expectations for mocked functions
    will_return(stub_mvprintw, 1);

    render_text(text, x, y);

    // Add assertions
    assert_true(stub_mvprintw == mvprintw);
    assert_string_equal(stub_mvprintw_text, text);

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

