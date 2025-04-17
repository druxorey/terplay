#include "../lib/render.hpp"

void Render::outline(short &termWidth, short &termHeight) {
	int verticalStart = (termHeight - BOARD_HEIGHT) / 2;
	int horizontalStart = (termWidth - BOARD_WIDTH) / 2;
	int verticalEnd = verticalStart + BOARD_HEIGHT;
	int horizontalEnd = horizontalStart + BOARD_WIDTH;

	// Draw corners
	mvprintw(verticalStart, horizontalStart, "╭"); // Top-left corner
	mvprintw(verticalStart, horizontalEnd, "╮");   // Top-right corner
	mvprintw(verticalEnd, horizontalStart, "╰");   // Bottom-left corner
	mvprintw(verticalEnd, horizontalEnd, "╯");     // Bottom-right corner

	// Draw horizontal edges
	for (int j = horizontalStart + 1; j < horizontalEnd; j++) {
		mvprintw(verticalStart, j, "─");  // Top edge
		mvprintw(verticalEnd, j, "─");    // Bottom edge
	}

	// Draw vertical edges
	for (int i = verticalStart + 1; i < verticalEnd; i++) {
		mvprintw(i, horizontalStart, "│");  // Left edge
		mvprintw(i, horizontalEnd, "│");    // Right edge
	}
}
