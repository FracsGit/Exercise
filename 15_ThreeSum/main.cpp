#include<vector>
#include<map>
#include<iostream>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
{
	map<int, int> numCount;
	vector<vector<int>> result;
	for (int num : nums)
		++numCount[num];

	for (auto iteMin = numCount.begin(); iteMin != numCount.end(); ++iteMin)
	{
		int min = iteMin->first;
		if (min > 0)
			break;
		--iteMin->second;
		for (auto iteMiddle = iteMin; iteMiddle != numCount.end(); ++iteMiddle)
		{
			int middle = iteMiddle->first;
			int max = -(min + middle);
			if (max < middle)
				break;
			if (iteMiddle->second > 0)
			{
				auto iteMax = numCount.find(max);
				if (iteMax != numCount.end())
				{
					if ((max > middle) || (max == middle && iteMiddle->second > 1))
						result.push_back({ min, middle, max });
				}
			}
		}
	}

	return result;
}

int main()
{
	vector<int> v1 = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> r1 = threeSum(v1);
	for (vector<int> v : r1)
	{
		for (int num : v)
			cout << num << " ";
		cout << endl;
	}
	cout << endl;

	vector<int> v2 = { };
	vector<vector<int>> r2 = threeSum(v2);
	for (vector<int> v : r2)
	{
		for (int num : v)
			cout << num << " ";
		cout << endl;
	}
	cout << endl;

	vector<int> v3 = { -1, 0, 1, 2, -1, 1 };
	vector<vector<int>> r3 = threeSum(v3);
	for (vector<int> v : r3)
	{
		for (int num : v)
			cout << num << " ";
		cout << endl;
	}
	cout << endl;

	vector<int> v4 = { 0, 0, 0, 0 };
	vector<vector<int>> r4 = threeSum(v4);
	for (vector<int> v : r4)
	{
		for (int num : v)
			cout << num << " ";
		cout << endl;
	}
	cout << endl;

	system("Pause");
	return 0;
}