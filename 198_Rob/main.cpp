#include<vector>
#include<iostream>
using namespace std;

int rob(vector<int>& nums) 
{
	int size = nums.size();
	if (size == 0)
		return 0;

	int near = 0, notNear = 0;
	for (int i = 0; i < size; ++i)
	{
		int tempNear = nums[i] + notNear;
		int tempNotNear = near > notNear ? near : notNear;
		near = tempNear;
		notNear = tempNotNear;
	}

	int result = near > notNear ? near : notNear;
	return result;
}

int main()
{
	vector<int> v1 = { 1,2,3,1 };
	vector<int> v2 = { 2,7,9,3,1 };
	vector<int> v3 = { };
	vector<int> v4 = { 3,2,3,4 };
	vector<int> v5 = { 1,2,3,1,7,11 };
	cout << rob(v1) << endl;
	cout << rob(v2) << endl;
	cout << rob(v3) << endl;
	cout << rob(v4) << endl;
	cout << rob(v5) << endl;

	system("Pause");
	return 0;
}