#include <ncurses.h>
#include <unistd.h>

#pragma once

const short BOARD_WIDTH = 36;
const short BOARD_HEIGHT = 36;


struct Board {
    short xStart = 0;
    short xEnd = 0;
    short yStart = 0;
    short yEnd = 0;
};


class Render {
public:
	Board board;

	void printOutline();
	void printBoard();
	void printPlayer(short &playerXPosition, short &playerYPosition);
};
