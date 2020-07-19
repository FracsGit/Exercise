#include "stdafx.h"

int maxCoins(vector<int>& nums) 
{
	vector<int> val(nums.size() + 2, 0);
	val[0] = val[nums.size() + 1] = 1;
	for (int i = 0; i != nums.size(); ++i)
	{
		val[i + 1] = nums[i];
	}

	vector<vector<int>> result(val.size(), vector<int>(val.size(), 0));
	for (int i = val.size() - 2; i >= 0; --i)
	{
		for (int j = i + 2; j != val.size(); ++j)
		{
			for (int k = i + 1; k < j; ++k)
			{
				int sum = val[i] * val[k] * val[j];
				sum = sum + result[i][k] + result[k][j];
				result[i][j] = max(result[i][j], sum);
			}
		}
	}

	return result[0][val.size() - 1];
}