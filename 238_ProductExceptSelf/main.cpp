#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) 
{
	int size = nums.size();
	if (size < 2)
		return nums;
	vector<int> output(size);
	output[0] = nums[0];
	for (int i = 1; i < size - 1; ++i)
	{
		output[i] = output[i - 1] * nums[i];
	}
	int tail = 1;
	for (int i = size - 1; i > 0; --i)
	{
		output[i] = output[i - 1] * tail;
		tail *= nums[i];
	}
	output[0] = tail;

	return output;
}

int main()
{
	vector<int> v1 = { 1,2,3,4 };
	vector<int> v2 = {  };
	vector<int> v3 = { 1 };
	vector<int> v4 = { 1,2 };

	v1 = productExceptSelf(v1);
	for (int num : v1)
		cout << num << " ";
	cout << endl;
	v2 = productExceptSelf(v2);
	for (int num : v2)
		cout << num << " ";
	cout << endl;
	v3 = productExceptSelf(v3);
	for (int num : v3)
		cout << num << " ";
	cout << endl;
	v4 = productExceptSelf(v4);
	for (int num : v4)
		cout << num << " ";
	cout << endl;

	system("Pause");
	return 0;
}