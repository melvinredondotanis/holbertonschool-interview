#include "sandpiles.h"

/**
 * sandpiles_sum - Sum two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int flags[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	while (grid1_unstable(grid1, flags))
	{

		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (flags[i][j])
					topple(grid1, i, j);
			}
		}
	}
}

/**
 * grid1_unstable - Check if grid1 is unstable
 * @grid1: 3x3 grid
 * @flags: 3x3 flags
 *
 * Return: 1 if unstable, 0 otherwise
 */
int grid1_unstable(int grid1[3][3], int flags[3][3])
{
	int i, j;
	int unstable = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				flags[i][j] = 1;
				unstable = 1;
			}
			else
				flags[i][j] = 0;
		}
	}
	return (unstable);
}

/**
 * topple - Topple a cell in the grid
 * @grid1: 3x3 grid
 * @i: Row index
 * @j: Column index
 */
void topple(int grid1[3][3], int i, int j)
{
	grid1[i][j] -= 4;

	if (i - 1 >= 0)
		grid1[i - 1][j] += 1;
	if (i + 1 < 3)
		grid1[i + 1][j] += 1;
	if (j - 1 >= 0)
		grid1[i][j - 1] += 1;
	if (j + 1 < 3)
		grid1[i][j + 1] += 1;
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
