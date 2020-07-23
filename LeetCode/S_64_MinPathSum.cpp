#include "stdafx.h"

int minPathSum(vector<vector<int>>& grid) 
{
	if (grid.empty() || grid[0].empty())
		return 0;
	int x = grid.size();
	int y = grid[0].size();

	vector<int> result = grid[x - 1];

	for (int i = y - 2; i >= 0; --i)
	{
		result[i] += result[i + 1];
	}

	for (int i = x - 2; i >= 0; --i)
	{
		result[y - 1] += grid[i][y - 1];
		for (int j = y - 2; j >= 0; --j)
		{
			result[j] = grid[i][j] + min(result[j + 1], result[j]);
		}
	}

	return result[0];
}