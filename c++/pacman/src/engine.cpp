#include <ncurses.h>
#include <iostream>

#include "../lib/engine.hpp"
#include "../lib/map.hpp"

void movePlayer(short &playerXPosition, short &playerYPosition, short rect_x, short rect_y, char &lastMove) {

	int xReference = playerXPosition - rect_x;
	int yReference = playerYPosition - rect_y;

	int ch = getch();

	switch (ch) {
		case KEY_UP:
			if (map[yReference - 1][xReference] == ' ') {playerYPosition--; lastMove = 'w';}
			else if (playerYPosition == rect_y) playerYPosition = rect_y + BOARD_MAX_HEIGHT - 2;
			break;
		case KEY_DOWN:
			if (map[yReference + 1][xReference] == ' ') {playerYPosition++; lastMove = ' ';}
			else if (playerYPosition == rect_y + BOARD_MAX_HEIGHT - 1) playerYPosition = rect_y + 1;
			break;
		case KEY_LEFT:
			if (map[yReference][xReference - 1] == ' ') playerXPosition--;
			else if (playerXPosition == rect_x) playerXPosition = rect_x + BOARD_MAX_WIDTH - 2;
			break;
		case KEY_RIGHT:
			if (map[yReference][xReference + 1] == ' ') playerXPosition++;
			else if (playerXPosition == rect_x + BOARD_MAX_WIDTH - 2) playerXPosition = rect_x;
			break;
		case 'q':
			endwin();
			exit(0);
			break;
	}
}
