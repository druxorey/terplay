#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <locale.h>

#include "lib/engine.hpp"
#include "lib/renderer.hpp"

int score = 0;

int main() {
    setlocale(LC_ALL, ""); // Set the locale for the program
    initscr(); // Initialize the ncurses screen
    cbreak(); // Disable line buffering, pass on everything to the program
    noecho(); // Don't echo input characters
    curs_set(FALSE); // Hide the default screen cursor
    keypad(stdscr, TRUE); // Enable reading of function keys (like F1, F2, arrow keys)
    start_color(); // Enable color functionality in ncurses

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);

	Renderer mainRender;

	short TERM_WIDTH, TERM_HEIGHT;
	short playerXPosition, playerYPosition;
	short anchorXPoint, anchorYPoint;

	char lastMove = ' ';

	getmaxyx(stdscr, TERM_HEIGHT, TERM_WIDTH);

	playerXPosition = (TERM_WIDTH / 2) - 1;
	playerYPosition = (TERM_HEIGHT / 2);

	do {
		getmaxyx(stdscr, TERM_HEIGHT, TERM_WIDTH);

		anchorXPoint = (TERM_WIDTH - BOARD_MAX_WIDTH) / 2;
		anchorYPoint = (TERM_HEIGHT - BOARD_MAX_HEIGHT) / 2;

		clear();

		mvprintw(0, 0, "TERM_WIDTH: %d, TERM_HEIGHT: %d", TERM_WIDTH, TERM_HEIGHT);
		mvprintw(1, 0, "playerXPosition: %d, playerYPosition: %d", playerXPosition, playerYPosition);
		mvprintw(2, 0, "rect_x: %d, rect_y: %d", anchorXPoint, anchorYPoint);

		mainRender.board(anchorXPoint, anchorYPoint);
		mainRender.player(playerXPosition, playerYPosition);

		mvprintw(BOARD_MAX_HEIGHT + anchorYPoint, TERM_WIDTH / 2 - 4, "Score: %d", score);

		refresh();

		movePlayer(playerXPosition, playerYPosition, anchorXPoint, anchorYPoint, lastMove);

	} while (true);


	endwin();
	return 0;
}
