//https://projecteuler.net/problem=15

//Lattice paths

//Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

//How many such routes are there through a 20×20 grid?

long long p015()
{
	//an NxN grid has (N+1)x(N+1) vertices that we can visit
	long long grid[21][21] = { {0} };
	grid[0][0] = 1;
	for (auto i = 0; i < 21; ++i)
	{
		for (auto j = 0; j < 21; ++j)
		{
			//if a vertex has n ways to reach it, then the neighboring vertices
			//have an additional n ways to reach them as well
			if (j < 20)
				grid[i][j + 1] += grid[i][j];
			if (i < 20)
				grid[i + 1][j] += grid[i][j];
		}
	}
	//return the n ways to reach the corner vertex
	return grid[20][20];
}
