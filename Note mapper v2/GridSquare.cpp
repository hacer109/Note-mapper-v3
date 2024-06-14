#include "GridSquare.h"
#include <raylib.h>


void GridSquare::SquareDraw()
{
	//DrawRectangle(squareX, squareY, 16 * SquareSize, 16 * SquareSize, squareColor);
	rect = { float(squareX),float(squareY), float(16) * float(SquareSize), float(16) * float(SquareSize) };
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

	if (IsKeyPressed(KEY_X)&& hoveredOver) {
		drawNote = !drawNote;
	}

	

}
void GridSquare::SquareUpdate() {

	if (drawNote)DrawRectangle(squareX, squareY, 10, 10, RED);
	SquareDraw();
	IsMouseClickingThis();

}
