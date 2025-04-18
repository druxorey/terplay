#include <ncurses.h>
#include <unistd.h>

#pragma once

const short BOARD_WIDTH = 36;
const short BOARD_HEIGHT = 36;


struct Player {
	short x = 0;
	short y = 0;
};


struct Board {
    short xStart = 0;
    short xEnd = 0;
    short yStart = 0;
    short yEnd = 0;
};


class Render {
public:
	Board boardCoords;
	Player playerPos;

	void printOutline();
	void printBoard();
	void printPlayer();
};
