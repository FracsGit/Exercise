#include "stdafx.h"

int main()
{
	int minPathSum(vector<vector<int>>& grid);

	vector<vector<int>> grid = { {1, 3, 1},{1, 5, 1},{4, 2, 1} };

	cout << minPathSum(grid) << endl;

	system("Pause");
	return 0;
}