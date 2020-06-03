#include<iostream>
#include<vector>
using namespace std;

double new21Game(int N, int K, int W) 
{
	if (K <= 0)
		return 1;
	if (W <= 0)
		return 0;
	vector<double> possibility(K+W);

	int limit = K + W;
	limit = limit > N + 1 ? N + 1 : limit;
	for (int i = K; i < limit; ++i)
		possibility[i] = 1;

	for (int i = 1; i <= W; ++i)
		possibility[K - 1] += possibility[K - 1 + i];
	possibility[K - 1] /= W;

	if(K > 1)
		for (int i = K - 2; i >= 0; --i)
			possibility[i] = possibility[i + 1] - (possibility[i + W + 1] - possibility[i + 1]) / W;

	return possibility[0];
}

int main()
{
	cout << new21Game(10, 1, 10) << endl;
	cout << new21Game(6, 1, 10) << endl;
	cout << new21Game(15, 11, 1) << endl;
	cout << new21Game(21, 17, 10) << endl;
	cout << new21Game(10, 0, 10) << endl;
	cout << new21Game(0, 0, 10) << endl;
	cout << new21Game(10, 1, 0) << endl;
	cout << new21Game(10000, 10000, 10) << endl;
	cout << new21Game(10000, 10000, 10000) << endl;
	cout << new21Game(8324, 2763, 6645) << endl;
	system("Pause");
	return 0;
}