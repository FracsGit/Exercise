#include<iostream>
#include<vector>
using namespace std;

int climbStairs(int n) 
{
	if (n < 2)
		return 1;

	vector<int> path(n + 1, 1);

	for (int i = 2; i <= n; ++i)
		path[i] = path[i - 2] + path[i - 1];

	return path[n];
}

int main()
{
	cout << climbStairs(0) << endl;
	cout << climbStairs(1) << endl;
	cout << climbStairs(2) << endl;
	cout << climbStairs(3) << endl;
	cout << climbStairs(4) << endl;
	cout << climbStairs(5) << endl;
	cout << climbStairs(6) << endl;
	cout << climbStairs(7) << endl;
	cout << climbStairs(8) << endl;
	cout << climbStairs(9) << endl;
	cout << climbStairs(10) << endl;
	cout << climbStairs(40) << endl;

	system("Pause");
	return 0;
}