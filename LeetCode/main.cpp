#include "stdafx.h"

int main()
{
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

	vector<vector<int>> obstacleGrid = { {0,0,1,0}, {0,1,0,0},{0,0,0,0} };

	cout << uniquePathsWithObstacles(obstacleGrid) << endl;

	system("Pause");
	return 0;
}