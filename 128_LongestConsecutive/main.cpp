#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int longestConsecutive(vector<int>& nums) 
{
	unordered_set<int> num_set;
	for (const int& num : nums) 
		num_set.insert(num);

	int longestStreak = 0;

	for (const int& num : num_set) 
	{
		if (!num_set.count(num - 1)) 
		{
			int currentNum = num;
			int currentStreak = 1;

			while (num_set.count(currentNum + 1)) 
			{
				currentNum += 1;
				currentStreak += 1;
			}

			longestStreak = max(longestStreak, currentStreak);
		}
	}

	return longestStreak;
}

int main()
{
	vector<int> v1 = { 100, 4, 200, 1, 3, 2 };
	vector<int> v2 = {  };
	vector<int> v3 = { 100 };
	vector<int> v4 = { 100, 4, 200 };
	
	cout << longestConsecutive(v1) << endl;
	cout << longestConsecutive(v2) << endl;
	cout << longestConsecutive(v3) << endl;
	cout << longestConsecutive(v4) << endl;

	system("Pause");
	return 0;
}