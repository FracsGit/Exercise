#include "stdafx.h"

int main()
{
	int minimumTotal(vector<vector<int>>& triangle);
	vector<vector<int>> triangle = { {2},{3, 4},{6, 5, 7},{4, 1, 8, 3} };
	
	cout << minimumTotal(triangle) << endl;

	system("Pause");
	return 0;
}