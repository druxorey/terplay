#include "../lib/render.hpp"

void Render::printOutline() {

	// Draw corners
	mvprintw(this->boardCoords.yStart, this->boardCoords.xStart, "╭"); // Top-left corner
	mvprintw(this->boardCoords.yStart, this->boardCoords.xEnd, "╮");   // Top-right corner
	mvprintw(this->boardCoords.yEnd, this->boardCoords.xStart, "╰");   // Bottom-left corner
	mvprintw(this->boardCoords.yEnd, this->boardCoords.xEnd, "╯");     // Bottom-right corner

	// Draw x edges
	for (int j = this->boardCoords.xStart + 1; j < this->boardCoords.xEnd; j++) {
		mvprintw(this->boardCoords.yStart, j, "─");  // Top edge
		mvprintw(this->boardCoords.yEnd, j, "─");    // Bottom edge
	}

	// Draw y edges
	for (int i = this->boardCoords.yStart + 1; i < this->boardCoords.yEnd; i++) {
		mvprintw(i, this->boardCoords.xStart, "│");  // Left edge
		mvprintw(i, this->boardCoords.xEnd, "│");    // Right edge
	}
}

void Render::printPlayer() {
	mvprintw(this->boardCoords.yStart + this->playerPos.y, this->boardCoords.xStart + this->playerPos.x, "◉"); // Player character
}
