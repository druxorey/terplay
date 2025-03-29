#include <ncurses.h>
#include <cstdlib> // For srand and rand
#include <ctime> // For time
#include "../lib/renderer.hpp"
#include "../lib/map.hpp"

void Renderer::board(int rect_x, int rect_y) {
	attron(COLOR_PAIR(2));
	for (int i = 0; i < BOARD_MAX_HEIGHT; ++i) {
		for (int j = 0; j < BOARD_MAX_WIDTH; ++j) {
			switch (map[i][j]) {
				case '1': mvprintw(rect_y + i, rect_x + j, "╔"); break;
				case '2': mvprintw(rect_y + i, rect_x + j, "╗"); break;
				case '3': mvprintw(rect_y + i, rect_x + j, "╚"); break;
				case '4': mvprintw(rect_y + i, rect_x + j, "╝"); break;
				case '-': mvprintw(rect_y + i, rect_x + j, "═"); break;
				case '|': mvprintw(rect_y + i, rect_x + j, "║"); break;
				case ' ': mvprintw(rect_y + i, rect_x + j, " "); break;
				case '$': mvprintw(rect_y + i, rect_x + j, " "); break;
				case '@': mvprintw(rect_y + i, rect_x + j, "@"); break;
				}
		}
	}
	attron(COLOR_PAIR(2));
}

void Renderer::player(int playerXPosition, int playerYPosition) {
	attron(COLOR_PAIR(1));
	mvprintw(playerYPosition, playerXPosition, "O");
	attroff(COLOR_PAIR(1));
}

void Renderer::generateFood() {
	srand(time(NULL));

	for (int i = 0; i < BOARD_MAX_HEIGHT; ++i) {
		int x = rand() % BOARD_MAX_WIDTH;
		int y = rand() % BOARD_MAX_HEIGHT;
		if (map[y][x] == ' ') {
			map[y][x] = '@';
		}
	}
}
