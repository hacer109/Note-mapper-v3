#include "GridSquare.h"
#include <raylib.h>


void GridSquare::SquareDraw()
{
	//DrawRectangle(squareX, squareY, 16 * SquareSize, 16 * SquareSize, squareColor);
	DrawRectangleRec(rect, squareColor);
	NoteDraw();
}

void GridSquare::NoteDraw() {

	

}

void GridSquare::IsMouseClickingThis() {

	Vector2 mousePos = GetMousePosition();
	
	if (CheckCollisionPointRec(mousePos, rect)) {
		
		squareColor = GRAY;
		if(!IsKeyDown(KEY_G))
		hoveredOver = true;

	}
	else
	{
		squareColor = DefaultSquareColor;
		hoveredOver = false;
	}
}
void GridSquare::SquareUpdate() {
	SquareDraw();
	IsMouseClickingThis();

}
