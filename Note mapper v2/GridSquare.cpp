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

	DrawCircle(squareX+24, squareY+24, 20, RED);

}

void GridSquare::IsMouseClickingThis() {

	Vector2 mousePos = GetMousePosition();
	
	if (CheckCollisionPointRec(mousePos, rect)) {
		
		squareColor = GRAY;
		if(!IsKeyDown(KEY_G))
		hoveredOver = true;

		if (IsKeyPressed(KEY_A))
		{
			drawNote = false;
		}
		
	}
	else
	{
		squareColor = DefaultSquareColor;
		hoveredOver = false;
	}

	std::cout << drawNote << "\n";

	

}
void GridSquare::SquareUpdate() {

	if (drawNote == true) {
		NoteDraw();
	}
	SquareDraw();
	IsMouseClickingThis();

}
