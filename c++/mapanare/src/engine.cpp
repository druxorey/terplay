#include "../lib/engine.hpp"

void movePlayer(short &playerXPosition, short &playerYPosition) {
	int ch = getch();

	switch (ch) {
        case KEY_UP:
            if (playerYPosition > 1) {
                playerYPosition--;
            }
            break;
        case KEY_DOWN:
            if (playerYPosition < 35) {
                playerYPosition++;
            }
            break;
        case KEY_LEFT:
            if (playerXPosition > 1) {
                playerXPosition--;
            }
            break;
        case KEY_RIGHT:
            if (playerXPosition < 35) {
                playerXPosition++;
            }
            break;
		default:
			break;
	}
}
