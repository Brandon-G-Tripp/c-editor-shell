#ifndef TERMINAL_H
#define TERMINAL_H

// Init terminal and ncurses
void init_terminal();

// Shut down terminal and cleanup 
void shutdown_terminal();

// Handle keyborad input 
void handle_key_press();

// Get enxt key press, block until key is pressed
int get_key_press();

// Render the terminal UI
void render_ui();

// Render text at position
void render_text(char* text, int x, int y);

// Update cursor position
void update_cursor(int x, int y);

// Clear screen 
void clear_screen();

// Refresh screen
void refresh_screen();

#endif
