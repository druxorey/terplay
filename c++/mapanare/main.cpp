#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <locale.h>

#include "lib/render.hpp"
#include "lib/engine.hpp"

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
	short PLAYER_POS_X = 0, PLAYER_POS_Y = 0;

	Render render;

	do {
		getmaxyx(stdscr, TERM_HEIGHT, TERM_WIDTH); // Get the current terminal size

		render.board.yStart = (TERM_HEIGHT - BOARD_HEIGHT) / 2;
		render.board.xStart = (TERM_WIDTH - BOARD_WIDTH) / 2;
		render.board.yEnd = render.board.yStart + BOARD_HEIGHT;
		render.board.xEnd = render.board.xStart + BOARD_WIDTH;

		movePlayer(PLAYER_POS_X, PLAYER_POS_Y); // Move the player based on input

		clear();
		mvprintw(0, 0, "TERM_WIDTH: %d, TERM_HEIGHT: %d", TERM_WIDTH, TERM_HEIGHT);

		render.printOutline();
		render.printPlayer(PLAYER_POS_X, PLAYER_POS_Y);

		refresh();
	} while (true);

	endwin();

	return 0;
}
