#include "stdafx.h"

int main()
{
	int kthSmallest(vector<vector<int>>& matrix, int k);
	
	int k = 1;
	vector<vector<int>> matrix = { {2000000000} };

	cout << kthSmallest(matrix, k) << endl;

	system("Pause");
	return 0;
}