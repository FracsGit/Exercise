#include "stdafx.h"

int minArray(vector<int>& numbers, int l, int r)
{
	if (l > r)
		return 0;

	if (numbers[l] < numbers[r])
		return numbers[l];

	while (l < r - 1)
	{
		int m = (l + r) / 2;
		if (numbers[m] < numbers[r])
		{
			r = m;
		}
		else if (numbers[m] > numbers[r])
		{
			l = m;
		}
		else if (numbers[m] == numbers[r])
		{
			return min(minArray(numbers, l, m), minArray(numbers, m, r));
		}
	}
	return numbers[r];
}

int minArray(vector<int>& numbers) 
{
	return minArray(numbers, 0, numbers.size() - 1);
}