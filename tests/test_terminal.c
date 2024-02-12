#include "../include/terminal.h"


#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h> // needed for cmocka
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

// Test init and shutdown 
void test_init_shutdown() {
    will_return(__wrap_initscr, NULL);
    will_return(__wrap_endwin, OK);

    init_terminal();
    shutdown_terminal();

    assert_true(init_called);
    assert_true(shutdown_called);
}

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_init_shutdown),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
} 

