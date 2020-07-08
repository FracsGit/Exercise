#include "stdafx.h"

vector<int> divingBoard(int shorter, int longer, int k) 
{
	if (k == 0)
		return vector<int>();

	if (shorter == longer)
		return vector<int>(1, shorter * k);

	vector<int> result(k + 1, 0);

	int dif = longer - shorter;
	for (int i = 0, length = shorter * k - dif; i <= k; ++i)
	{
		length += dif;
		result[i] = length;
	}

	return result;
}