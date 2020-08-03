#include "stdafx.h"

string addStrings(string num1, string num2) 
{
	string result;
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	int add = 0;
	while (i >= 0 || j >= 0 || add > 0)
	{
		int x = i >= 0 ? num1[i] - '0' : 0;
		int y = j >= 0 ? num2[j] - '0' : 0;
		int temp = x + y + add;
		result.push_back(temp % 10 + '0');
		add = temp / 10;
		--i;
		--j;
	}

	reverse(result.begin(), result.end());
	return result;
}