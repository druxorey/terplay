#include <ncurses.h>
#include <iostream>

#include "../lib/engine.hpp"
#include "../lib/map.hpp"

bool movePlayer(short &playerXPosition, short &playerYPosition, short rect_x, short rect_y, char &lastMove, int &score) {

	int xReference = playerXPosition - rect_x;
	int yReference = playerYPosition - rect_y;

	int ch = getch();

	// No input detected, continue moving in the last direction
	if (ch == ERR) ch = lastMove;

	switch (ch) {
		case KEY_UP:
		case 'w': {
			if (map[yReference - 1][xReference] == ' ') {playerYPosition--; lastMove = 'w';}
			if (map[yReference - 1][xReference] == '@') {playerYPosition--; lastMove = 'w'; score++;}
			return true;
		}
		case KEY_DOWN:
		case 's':
			if (map[yReference + 1][xReference] == ' ') {playerYPosition++; lastMove = 's';}
			if (map[yReference + 1][xReference] == '@') {playerYPosition++; lastMove = 's'; score++;}
			return true;
		case KEY_LEFT:
		case 'a':
			if (map[yReference][xReference - 1] == ' ') {playerXPosition--; lastMove = 'a';}
			if (map[yReference][xReference - 1] == '@') {playerXPosition--; lastMove = 'a'; score++;}
			return true;
		case KEY_RIGHT:
		case 'd':
			if (map[yReference][xReference + 1] == ' ') {playerXPosition++; lastMove = 'd';}
			if (map[yReference][xReference + 1] == '@') {playerXPosition++; lastMove = 'd'; score++;}
			return true;
		case 'q':
			endwin();
			exit(0);
	}

	return false;
}
