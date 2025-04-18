#include "../lib/render.hpp"

void Render::printOutline() {

	// Draw corners
	mvprintw(this->board.yStart, this->board.xStart, "╭"); // Top-left corner
    mvprintw(this->board.yStart, this->board.xEnd, "╮");   // Top-right corner
    mvprintw(this->board.yEnd, this->board.xStart, "╰");   // Bottom-left corner
    mvprintw(this->board.yEnd, this->board.xEnd, "╯");     // Bottom-right corner

    // Draw x edges
    for (int j = this->board.xStart + 1; j < this->board.xEnd; j++) {
        mvprintw(this->board.yStart, j, "─");  // Top edge
        mvprintw(this->board.yEnd, j, "─");    // Bottom edge
    }

    // Draw y edges
    for (int i = this->board.yStart + 1; i < this->board.yEnd; i++) {
        mvprintw(i, this->board.xStart, "│");  // Left edge
        mvprintw(i, this->board.xEnd, "│");    // Right edge
    }
}

void Render::printPlayer(short &playerXPosition, short &playerYPositiion) {
	mvprintw(this->board.yStart + playerYPositiion, this->board.xStart + playerXPosition, "◉"); // Player character
}
