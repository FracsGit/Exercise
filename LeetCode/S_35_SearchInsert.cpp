#include "stdafx.h"

int searchInsert(vector<int>& nums, int target) 
{
	if (nums.empty())
		return 0;
	if (nums[0] >= target)
		return 0;
	if (nums[nums.size() - 1] < target)
		return nums.size();

	int l = 0, r = nums.size() - 1;
	while (l != r - 1)
	{
		int m = (l + r) / 2;
		if (nums[m] < target)
			l = m;
		else
			r = m;
	}
	return r;
}