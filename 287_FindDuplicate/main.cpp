#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums) 
{
	int slow = 0, fast = 0;
	do
	{
		slow = nums[slow];
		fast = nums[nums[fast]];
	} while (slow != fast);
	slow = 0;
	while (slow != fast)
	{
		slow = nums[slow];
		fast = nums[fast];
	}

	return slow;
}

int main()
{
	vector<int> v1 = { 1,3,4,2,2 };
	vector<int> v2 = { 3,1,3,4,2 };

	cout << findDuplicate(v1) << endl;
	cout << findDuplicate(v2) << endl;

	system("Pause");
	return 0;
}