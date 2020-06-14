#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findBestValue(vector<int>& arr, int target) 
{
	int size = arr.size();
	if (size == 0)
		return 0;

	sort(arr.begin(), arr.end());
	int sum = 0, count = 0;
	bool notBig = true;
	for (int i = 0; notBig && i < size; ++i)
	{
		int temp = sum + arr[i] * (size - count);
		if (temp > target)
		{
			notBig = false;
			break;
		}
		else if (temp == 0)
			return arr[i];
		else
		{
			sum += arr[i];
			++count;
		}
	}

	if (notBig)
		return arr[size - 1];

	int n = size - count;
	int deviate = target - sum;
	int value = (deviate + (n - 1) / 2) / n;

	return value;
}

int main()
{
	vector<int> v1 = { 4,9,3 };
	int t1 = 10;
	cout << findBestValue(v1, t1) << endl;

	vector<int> v2 = { 2,3,5 };
	int t2 = 10;
	cout << findBestValue(v2, t2) << endl;

	vector<int> v3 = { 60864,25176,27249,21296,20204 };
	int t3 = 56803;
	cout << findBestValue(v3, t3) << endl;

	vector<int> v4 = { 4,5,6 };
	int t4 = 10;
	cout << findBestValue(v4, t4) << endl;

	vector<int> v5 = { 1,2,3 };
	int t5 = 10;
	cout << findBestValue(v5, t5) << endl;

	vector<int> v6 = { };
	int t6 = 10;
	cout << findBestValue(v6, t6) << endl;

	system("Pause");
	return 0;
}