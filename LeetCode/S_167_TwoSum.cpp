#include "stdafx.h"

int find(vector<int>& numbers, int target, int l)
{
	int size = numbers.size();
	int r = size - 1;
	if (l == size || numbers[l] > target || numbers[r] < target)
		return -1;

	if (numbers[l] == target)
		return l;
	if (numbers[r] == target)
		return r;

	while (l != r - 1)
	{
		int m = (l + r) / 2;
		if (numbers[m] == target)
			return m;
		else if (numbers[m] > target)
			r = m;
		else
			l = m;
	}

	return -1;
}

vector<int> twoSum(vector<int>& numbers, int target)
{
	int size = numbers.size();
	if (size < 2 || numbers[0] + numbers[1]>target || numbers[size - 1] + numbers[size - 2] < target)
		return vector<int>();
	
	for (int i = 0; i < size; ++i)
	{
		int r = find(numbers, target - numbers[i], i + 1);
		if (r != -1)
		{
			return vector<int>{ i + 1, r + 1 };
		}
	}

	return vector<int>();
}