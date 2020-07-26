#include "stdafx.h"

int longestIncreasingPath(vector<vector<int>>& matrix, vector<vector<int>>& record, int x, int y)
{
	if (record[x][y] != 0)
		return record[x][y];

	int temp = 0;
	if (x > 0 && matrix[x - 1][y] > matrix[x][y])
		temp = max(temp, longestIncreasingPath(matrix, record, x - 1, y));
	if (x != matrix.size() - 1 && matrix[x + 1][y] > matrix[x][y])
		temp = max(temp, longestIncreasingPath(matrix, record, x + 1, y));
	if (y > 0 && matrix[x][y - 1] > matrix[x][y])
		temp = max(temp, longestIncreasingPath(matrix, record, x, y - 1));
	if (y != matrix[0].size() - 1 && matrix[x][y + 1] > matrix[x][y])
		temp = max(temp, longestIncreasingPath(matrix, record, x, y + 1));

	record[x][y] = 1 + temp;
	return record[x][y];
}

int longestIncreasingPath(vector<vector<int>>& matrix) 
{
	int x = matrix.size();
	if (x == 0)
		return 0;
	int y = matrix[0].size();
	if (y == 0)
		return 0;

	vector<vector<int>> record(x, vector<int>(y, 0));
	int result = 0;
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			result = max(result, longestIncreasingPath(matrix, record, i, j));
		}
	}

	return result;
}