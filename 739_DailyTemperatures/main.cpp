#include<vector>
#include<stack>
#include<iostream>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) 
{
	stack<int> s;
	int size = T.size();
	vector<int> result(size);

	for (int i = 0; i < size; ++i)
	{
		while (!s.empty() && T[s.top()] < T[i])
		{
			result[s.top()] = i - s.top();
			s.pop();
		}
		s.push(i);
	}
	return result;
}

int main()
{
	vector<int> t1 = { 73, 74, 75, 71, 69, 72, 76, 73 };
	vector<int> d1 = dailyTemperatures(t1);
	for (int x : d1)
		cout << x << " ";
	cout << endl;

	vector<int> t2 = { };
	vector<int> d2 = dailyTemperatures(t2);
	for (int x : d2)
		cout << x << " ";
	cout << endl;

	vector<int> t3 = { 73, 73 };
	vector<int> d3 = dailyTemperatures(t3);
	for (int x : d3)
		cout << x << " ";
	cout << endl;

	system("Pause");
	return 0;
}