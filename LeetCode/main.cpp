#include "stdafx.h"

int main()
{
	vector<int> twoSum(vector<int>& numbers, int target);

	vector<int> numbers = { 2, 7, 11, 15 };
	int target = 12;

	for (int x : twoSum(numbers, target))
	{
		cout << x << endl;
	}

	system("Pause");
	return 0;
}