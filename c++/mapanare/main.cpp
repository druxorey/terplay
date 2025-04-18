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
	getmaxyx(stdscr, TERM_HEIGHT, TERM_WIDTH); // Get the current terminal size

	Render render;

	render.playerPos.x = 18;
	render.playerPos.y = 18;

	do {
		getmaxyx(stdscr, TERM_HEIGHT, TERM_WIDTH); // Get the current terminal size

		render.boardCoords.yStart = (TERM_HEIGHT - BOARD_HEIGHT) / 2;
		render.boardCoords.xStart = (TERM_WIDTH - BOARD_WIDTH) / 2;
		render.boardCoords.yEnd = render.boardCoords.yStart + BOARD_HEIGHT;
		render.boardCoords.xEnd = render.boardCoords.xStart + BOARD_WIDTH;

		movePlayer(render.playerPos.x, render.playerPos.y); // Move the player based on input

		clear();
		mvprintw(0, 0, "TERM_WIDTH: %d, TERM_HEIGHT: %d", TERM_WIDTH, TERM_HEIGHT);
		mvprintw(1, 0, "Player X: %d, Player Y: %d", render.playerPos.x, render.playerPos.y);

		render.printOutline();
		render.printPlayer();

		refresh();
	} while (true);

	endwin();

	return 0;
}
