#include "game.h"
#include "grid.h"

int main()
{
	/*
	Initialize grid:
	- number of cells for the width
	- number of cells for the height
	- size of the cell in pixels
	- distance between each cell in pixels
	*/
	Grid grid(100, 50, 15, 1);
	Game game(grid, "Etienne's Game Of Life!");
	game.init(); //start init mode of the progamme
}