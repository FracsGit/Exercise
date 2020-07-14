#include "stdafx.h"

int minimumTotal(vector<vector<int>>& triangle) 
{
	if (triangle.empty())
		return 0;

	int n = triangle.size() - 1;
	vector<int> result = triangle[n];

	for (--n; n >= 0; --n)
	{
		for (int i = 0; i <= n; ++i)
			result[i] = triangle[n][i] + min(result[i], result[i + 1]);
	}
	return result[0];
}