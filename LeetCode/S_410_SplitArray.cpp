#include "stdafx.h"

int splitArray(vector<int>& nums, int m) 
{
	long long sum = 0;
	int maxNum = 0;
	for (int x : nums)
	{
		sum += x;
		maxNum = max(maxNum, x);
	}

	int l = maxNum;
	int r;
	if (sum > INT32_MAX)
		r = INT32_MAX;
	else
		r = static_cast<int>(sum);


	while (l < r)
	{
		int mid = l + (r - l) / 2;
		int count = 1;
		int tempSum = 0;
		for (int x : nums)
		{
			tempSum += x;
			if (tempSum > mid)
			{
				tempSum = x;
				++count;
			}
		}

		if (count > m)
			l = mid + 1;
		else
			r = mid;
	}

	return r;
}