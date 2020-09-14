#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

void estacopysec(int grid[3][3], int copy[3][3])
{
	int x, y;
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			copy[x][y] = grid[x][y];
		}
	}
}

static void print_grid(int grid[3][3])
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

void cualquiera(int grid1[3][3])
{
	int x, y, valor = 0, copy[3][3];
	estacopysec(grid1, copy);
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (copy[x][y] > 3)
			{
				valor = 1;
				grid1[x][y] -= 4;
				if (x + 1 < 3)
				{
					grid1[x + 1][y] += 1;
				}
				if (x - 1 >= 0)
				{
					grid1[x - 1][y] += 1;
				}
				if (y + 1 < 3)
				{
					grid1[x][y + 1] += 1;
				}
				if (y - 1 >= 0)
				{
					grid1[x][y - 1] += 1;
				}
			}
		}
	}
	if (valor == 1)
	{
		printf("=\n");
		print_grid(copy);
		cualquiera(grid1);
	}
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] += grid2[x][y];
		}
	}
	cualquiera(grid1);
}
