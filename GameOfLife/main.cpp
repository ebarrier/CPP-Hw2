#include "game.h"
#include "grid.h"

int main()
{
	Grid grid(100, 50, 15, 1);
	Game game(grid, "Etienne's Game Of Life!");
	game.init();
}