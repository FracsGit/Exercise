#include<vector>
#include<iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	auto iter1 = nums.begin();
	auto iter2 = iter1 + 1;
	bool find = false;
	for (; iter1 < nums.end() && find == false; iter1++)
	{
		for (iter2 = iter1 + 1; iter2 < nums.end() && find == false; iter2++)
		{
			if (*iter1 + *iter2 == target)
			{
				find = true;
			}
		}
	}
	vector<int> result;
	result.push_back((int)distance(nums.begin(), --iter1));
	result.push_back((int)distance(nums.begin(), --iter2));
	return result;
}

int main()
{
	vector<int> nums = { 2, 7, 11, 15};
	int target = 9;
	vector<int> result = twoSum(nums, target);
	cout << result[0] << result[1] << endl;
	
	system("Pause");
	return 0;
}

