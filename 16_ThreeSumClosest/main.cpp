#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int FindNearest(vector<int>& nums, int target, int left, int right)
{
	if (nums[left + 1] >= target)
		return nums[left + 1];
	if (nums[right - 1] <= target)
		return nums[right - 1];

	int l = left + 1;
	int r = right - 1;
	int m = (l + r) / 2;
	while (m != l)
	{
		if (nums[m] == target)
			return target;
		else if (nums[m] < target)
			l = m;
		else
			r = m;
		m = (l + r) / 2;
	}

	if (nums[m] < target)
		m++;
	if (nums[m] - target > target - nums[m - 1])
		return nums[m - 1];
	else
		return nums[m];
}

int twoSumClosest(vector<int>& nums, int target, int left)
{
	int size = nums.size();
	int result = nums[size - 1] + nums[size - 2];
	int value = nums[size - 1] + 1;
	for (int right = size - 1; right > left + 1; --right)
	{
		if (right != size - 1 && nums[right + 1] < target / 2)
			break;

		value = FindNearest(nums, target - nums[right], left, right);
		int temp = value + nums[right];
		if (abs(temp - target) < abs(result - target))
			result = temp;
		if (result == target)
			return target;
	}
	return result;
}

int threeSumClosest(vector<int>& nums, int target) 
{
	sort(nums.begin(), nums.end());
	int result = nums[0] + nums[1] + nums[2];
	int value = nums[0] * 2 - 1;
	int size = nums.size();
	for (int left = 0; left < size - 2; ++left)
	{
		if (left != 0 && nums[left - 1] > target / 3)
			break;

		value = twoSumClosest(nums, target - nums[left], left);
		int temp = value + nums[left];
		if (abs(temp - target) < abs(result - target))
			result = temp;
		if (result == target)
			return target;
	}
	return result;
}

int main()
{
	vector<int> v = { 0, 5, -1, -2, 4, -1, 0, -3, 4, -5 };
	int target = 1;
	cout << threeSumClosest(v, target) << endl;

	system("Pause");
	return 0;
}