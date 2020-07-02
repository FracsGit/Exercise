#include "stdafx.h"

int countSmall(vector<vector<int>>& matrix, int k)
{
	int count = 0;
	int x = 0, y = matrix.size() - 1;
	while (y >= 0)
	{
		while (x < static_cast<int>(matrix[0].size()) && matrix[y][x] <= k)
		{
			++x;
		}
		count += x;
		--y;
	}
	return count;
}

int kthSmallest(vector<vector<int>>& matrix, int k) 
{
	int l = matrix[0][0], r = matrix[matrix.size() - 1][matrix[0].size() - 1];
	while (l < r)
	{
		int m = (l + r) / 2;
		int count = countSmall(matrix, m);
		if (count >= k)
			r = m;
		else
			l = m + 1;
	}

	return l;
}