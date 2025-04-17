#include "../lib/engine.hpp"

void movePlayer(short &playerXPosition, short &playerYPosition) {
	int ch = getch();

	switch (ch) {
		case KEY_UP:
			playerYPosition--;
			break;
		case KEY_DOWN:
			playerYPosition++;
			break;
		case KEY_LEFT:
			playerXPosition--;
			break;
		case KEY_RIGHT:
			playerXPosition++;
			break;
		default:
			break;
	}
}
