#include "stdafx.h"

int main()
{
	int splitArray(vector<int>& nums, int m);

	vector<int> nums = { 7, 2, 5, 10, 8 };
	int m = 2;

	cout << splitArray(nums, m) << endl;

	system("Pause");
	return 0;
}