#include "gtest/gtest.h"
#include "GameOfLife.h"

TEST(GameOfLife, Create_a_board_with_all_cells_dead)
{
	GameOfLife life;
	life.GridSetup();

	for (int x = 0; x < 4; ++x)
	{
		for (int y = 0; y < 8; ++y)
		{
			EXPECT_FALSE(life.GameOfLifeGrid[x][y]);
		}
	}
}

TEST(GameOfLife, Create_a_single_live_cell)
{
	GameOfLife life;
	life.GridSetup();

	life.SetLiveState(true, 2, 3);

	EXPECT_TRUE(life.GameOfLifeGrid[2][3]);
}

TEST(GameOfLife, Any_live_cell_with_fewer_than_two_live_neighbours_dies)
{
	GameOfLife life;
	life.GridSetup();

	life.SetLiveState(true, 2, 3);

	life.SetStateBasedOnNeighbours(2, 3);

	EXPECT_FALSE(life.GameOfLifeGrid[2][3]);
}

TEST(GameOfLife, Any_live_cell_with_more_than_three_live_neighbours_dies)
{
	GameOfLife life;
	life.GridSetup();

	life.SetLiveState(true, 2, 3); // Cell to check (will die)

	life.SetLiveState(true, 1, 2);
	life.SetLiveState(true, 3, 2);
	life.SetLiveState(true, 1, 4);
	life.SetLiveState(true, 3, 4);

	life.SetStateBasedOnNeighbours(2, 3);

	EXPECT_FALSE(life.GameOfLifeGrid[2][3]);
}

TEST(GameOfLife, Any_live_cell_with_2_live_neighbours_stays_alive)
{
	GameOfLife life;
	life.GridSetup();

	life.SetLiveState(true, 2, 3); // Cell to check (will stay alive)

	life.SetLiveState(true, 1, 2);
	life.SetLiveState(true, 3, 2);

	life.SetStateBasedOnNeighbours(2, 3);

	EXPECT_TRUE(life.GameOfLifeGrid[2][3]);
}

TEST(GameOfLife, Any_live_cell_with_3_live_neighbours_stays_alive)
{
	GameOfLife life;
	life.GridSetup();

	life.SetLiveState(true, 2, 3); // Cell to check (will stay alive)

	life.SetLiveState(true, 1, 2);
	life.SetLiveState(true, 3, 2);
	life.SetLiveState(true, 3, 4);

	life.SetStateBasedOnNeighbours(2, 3);

	EXPECT_TRUE(life.GameOfLifeGrid[2][3]);
}

TEST(GameOfLife, Any_dead_cell_with_exactly_three_live_neighbours_becomes_alive)
{
	GameOfLife life;
	life.GridSetup();

	life.SetLiveState(true, 1, 2);
	life.SetLiveState(true, 3, 2);
	life.SetLiveState(true, 3, 4);

	life.SetStateBasedOnNeighbours(2, 3);

	EXPECT_TRUE(life.GameOfLifeGrid[2][3]);
}

TEST(GameOfLife, Bounds_check_to_stop_going_outside_of_array_when_counting_neighbours)
{
	GameOfLife life;
	life.GridSetup();

	life.SetLiveState(true, 3, 7);

	life.SetStateBasedOnNeighbours(3, 7);

	EXPECT_FALSE(life.GameOfLifeGrid[3][7]);
}