#include<vector>
#include<iostream>
using namespace std;

bool checkPossibility(vector<int>& nums);

int main()
{
	vector<int> nums1 = { 4, 2, 3 };
	vector<int> nums2 = { 4, 2, 1 };
	vector<int> nums3 = { 1, 5, 4, 6, 7, 10, 8, 9 };

	cout << checkPossibility(nums1) << endl;
	cout << checkPossibility(nums2) << endl;
	cout << checkPossibility(nums3) << endl;


	system("Pause");
	return 0;
}


bool checkPossibility(vector<int>& nums) 
{
	bool possibility = true;
	int count = 0;

	for (int i = 0; i < static_cast<int>(nums.size()) - 1;i++)
	{
		if (nums[i] > nums[i+1])
		{
			int countTemp = 0;

			if (i+2 < static_cast<int>(nums.size()) && nums[i] > nums[i+2])
			{
				countTemp++;
			}
			if (i-1 >= 0 && nums[i-1] > nums[i+1])
			{
				countTemp++;
			}
			if (countTemp > 0)
				count += countTemp;
			else
				count++;

		}

	}

	if (count > 1)
		possibility = false;

	return possibility;
}
