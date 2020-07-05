#include "stdafx.h"

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
	int x = obstacleGrid.size() - 1;
	int y = obstacleGrid[0].size() - 1;
	vector<vector<long long>> way(x + 1, vector<long long>(y + 1, 0));
	if (obstacleGrid[x][y] == 1 || obstacleGrid[0][0] == 1)
		return 0;
	way[x][y] = 1;
	for (int i = x; i >= 0 && obstacleGrid[i][y] == 0; --i)
		way[i][y] = 1;
	for (int i = y; i >= 0 && obstacleGrid[x][i] == 0; --i)
		way[x][i] = 1;
	for (int i = x - 1; i >= 0; --i)
	{
		for (int j = y - 1; j >= 0; --j)
		{
			if (obstacleGrid[i][j] == 1)
				way[i][j] = 0;
			else
				way[i][j] = way[i + 1][j] + way[i][j + 1];
		}
	}
	return static_cast<int>(way[0][0]);
}