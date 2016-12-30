#include "game.h"
#include "grid.h"

int main()
{
	Grid grid(6, 5, 20, 1);
	Game game(grid, "Stephan's Game Of Life!");
	game.run();
}