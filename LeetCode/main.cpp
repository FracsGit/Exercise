#include "stdafx.h"

int main()
{
	vector<int> countSmaller(vector<int>& nums);

	vector<int> nums = { 5,2,2,6,1 };
	
	vector<int> result = countSmaller(nums);
	for(int x:result)
		cout << x << endl;

	system("Pause");
	return 0;
}