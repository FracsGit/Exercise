#include "stdafx.h"

int integerBreak(int n)
{
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;

	vector<int> record(n + 1);

	record[0] = 1;
	record[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		int product = i;
		for (int j = 2; j <= i / 2 && j <= 3; ++j)
		{
			product = max(product, record[j] * record[i - j]);
		}
		record[i] = product;
	}
		
	return record[n];
}