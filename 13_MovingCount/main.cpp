#include<vector>
#include<iostream>
using namespace std;

int SumBit(int m)
{
	int sum = 0;
	while (m != 0)
	{
		sum += m % 10;
		m /= 10;
	}
	return sum;
}

int Count(int x, int y, int m, int n, int k, vector<vector<bool>> &map)
{
	map[x][y] = true;
	if (SumBit(x) + SumBit(y) > k)
		return 0;

	int count = 1;
	if (x + 1 < m && !map[x + 1][y])
		count += Count(x + 1, y, m, n, k, map);
	if (x - 1 >= 0 && !map[x - 1][y])
		count += Count(x - 1, y, m, n, k, map);
	if (y + 1 < n && !map[x][y + 1])
		count += Count(x, y + 1, m, n, k, map);
	if (y - 1 >= 0 && !map[x][y - 1])
		count += Count(x, y - 1, m, n, k, map);

	return count;
}


int movingCount(int m, int n, int k) 
{
	if (m < 1 || n < 1 || k < 0)
		return 0;
	if (k == 0)
		return 1;
	
	vector<vector<bool>> map(m);
	for (int i = 0; i < m; ++i)
		map[i].resize(n);

	int count = Count(0, 0, m, n, k, map);

	return count;
}

int main()
{
	cout << movingCount(10, 10, 5) << endl;
	cout << movingCount(2, 3, 1) << endl;
	cout << movingCount(3, 1, 0) << endl;
	cout << movingCount(0, 10, 5) << endl;
	cout << movingCount(10, 0, 5) << endl;


	system("Pause");
	return 0;
}