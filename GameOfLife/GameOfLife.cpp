#include "GameOfLife.h"

void GameOfLife::GridSetup()
{
	for (int x = 0; x < 4; ++x)
	{
		for (int y = 0; y < 8; ++y)
		{
			GameOfLifeGrid[x][y] = false;
		}
	}
}

void GameOfLife::SetLiveState(bool alive, int x, int y)
{
	GameOfLifeGrid[x][y] = alive;
}

void GameOfLife::SetStateBasedOnNeighbours(int x, int y)
{
	int numberOfNeighours = 0;

	for (int i = x - 1; i <= x + 1; ++i)
	{
		for (int j = y - 1; j <= y + 1; ++j)
		{
			if ((i != x) && (j != y) && (i < 4) && (j < 8) && (GameOfLifeGrid[i][j]))
				numberOfNeighours++;
		}
	}

	if ((numberOfNeighours < 2) || (numberOfNeighours > 3))
		SetLiveState(false, x, y);
	else if ((numberOfNeighours == 2) || ((numberOfNeighours == 3) && (GameOfLifeGrid[x][y])))
		SetLiveState(true, x, y);
	else if ((numberOfNeighours == 3) && (GameOfLifeGrid[x][y] == false))
		SetLiveState(true, x, y);
}