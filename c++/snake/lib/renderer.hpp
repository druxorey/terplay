#pragma once

const int BOARD_MAX_WIDTH = 25;
const int BOARD_MAX_HEIGHT = 21;

class Renderer {
	public:
		void board(int rect_x, int rect_y);
		void player(int playerXPosition, int playerYPosition);
		void generateFood();
};
