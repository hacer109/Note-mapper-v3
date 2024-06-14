#pragma once
#include "GridSquare.h"
#include <iostream>
class Grid
{
public:

	int posX, posY,size;
	int hoveredX;
	int hoveredY;
	int hoveredId;
	int hoveredId2;
	int offsetY;
	Grid(int x, int y, int size):posX(x), posY(y), size(size) {};
	Color cellColor;
	const int colnum = 16;
	GridSquare square[8][16];// GridSquare(posX, posY, 0, LIGHTGRAY, size);
	double sectionStartTime;
	double sectionEndTime;
	void AssignGrid() {
		
		bool isGray = true;
		
		
		for (int i = 0; i < 8; i++) {

			isGray = !isGray;
			
			for (int j = 0; j < colnum; j++) {

				switch (isGray) {

				case true:
					cellColor = LIGHTGRAY;
					break;
				case false:
					cellColor = WHITE;
					break;
				}

				
				square[i][j] = GridSquare(posX+(16 * i * size), posY+(16 * j * size), 0, cellColor, size);
				
				if (j % 1 == 0) {
					isGray = !isGray;
				}
				GridUpdate();
			}
		}
		GridUpdate();

	}
	void GridUpdate();
};

