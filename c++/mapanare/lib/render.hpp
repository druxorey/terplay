#include <ncurses.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#pragma once

const short BOARD_WIDTH = 36;
const short BOARD_HEIGHT = 36;

class Render {
public:
	void outline(short &termWidth, short &termHeight);
	void board(short termWidth, short termHeight);
	void player(short termWidth, short termHeight);
};
