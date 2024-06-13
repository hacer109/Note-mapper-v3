#include "Grid.h"


void Grid::GridUpdate() {
	
	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < colnum; j++) {

			square[i][j].SquareUpdate();
			square[i][j].ID = i;
			square[i][j].ID2 = j;
			switch (square[i][j].hoveredOver) {
			case true:
				
				hoveredX = square[i][j].squareX;
				hoveredY = square[i][j].squareY;
				hoveredId = square[i][j].ID;
				hoveredId2 = square[i][j].ID2;
				break;
			case false:
				break;
				
				
			}
		}
	}
	DrawRectangle(posX + (16 * 4 * size), posY, 5, 16 * 16 * size, GREEN);
}