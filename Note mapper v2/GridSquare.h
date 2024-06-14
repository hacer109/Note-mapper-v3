#pragma once
#include <raylib.h>
class GridSquare
{
public:
	int squareX, squareY, length,SquareSize,ID, ID2;
	bool hoveredOver;

	bool drawNote = false;

	Color squareColor;
	Color DefaultSquareColor;
	GridSquare(){}
	GridSquare(int X,int Y, int Length,Color color,int size): squareColor(color),DefaultSquareColor(color)
		,squareX(X),squareY(Y),length(Length),SquareSize(size){}
	Rectangle rect;// = { float(squareX),float(squareY), float(16) * float(SquareSize), float(16) * float(SquareSize) };
	void NoteDraw();
	void SquareDraw();
	void IsMouseClickingThis();
	void SquareUpdate();
};

