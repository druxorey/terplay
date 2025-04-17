#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <locale.h>

#include "lib/render.hpp"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, ""); // Set the locale for the program
    initscr(); // Initialize the ncurses screen
	timeout(300); // Non-blocking getch()
    cbreak(); // Disable line buffering, pass on everything to the program
    noecho(); // Don't echo input characters
    curs_set(FALSE); // Hide the default screen cursor
    keypad(stdscr, TRUE); // Enable reading of function keys (like F1, F2, arrow keys)
    start_color(); // Enable color functionality in ncurses
	
	short TERM_WIDTH = 0, TERM_HEIGHT = 0;

	Render render;

	do {
		getmaxyx(stdscr, TERM_HEIGHT, TERM_WIDTH); // Get the current terminal size

		clear();
		mvprintw(0, 0, "TERM_WIDTH: %d, TERM_HEIGHT: %d", TERM_WIDTH, TERM_HEIGHT);

		render.outline(TERM_WIDTH, TERM_HEIGHT);

		refresh();
		sleep(1);
	} while (true);

	endwin();

	return 0;
}
