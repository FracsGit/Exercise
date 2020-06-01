#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
{
	int max = 0;
	if(!candies.empty())
		max = *max_element(candies.begin(), candies.end());
	vector<bool> result;
	int checkNum = max - extraCandies;
	for (int num : candies)
	{
		result.push_back(num >= checkNum);
	}

	return result;
}

int main()
{
	vector<int> v1 = { 2,3,5,1,3 };
	int ex1 = 3;
	vector<int> v2 = { 4,2,1,1,2 };
	int ex2 = 1;
	vector<int> v3 = { 12,1,12 };
	int ex3 = 10;
	vector<int> v4 = {  };
	int ex4 = 3;
	vector<int> v5 = { 2,3,5,1,3 };
	int ex5 = 0;

	vector<bool> vb1 = kidsWithCandies(v1, ex1);
	for(bool b:vb1)
		cout << b << endl;
	vector<bool> vb2 = kidsWithCandies(v2, ex2);
	for (bool b : vb2)
		cout << b << endl;
	vector<bool> vb3 = kidsWithCandies(v3, ex3);
	for (bool b : vb3)
		cout << b << endl;
	vector<bool> vb4 = kidsWithCandies(v4, ex4);
	for (bool b : vb4)
		cout << b << endl;
	vector<bool> vb5 = kidsWithCandies(v5, ex5);
	for (bool b : vb5)
		cout << b << endl;

	system("Pause");
	return 0;
}