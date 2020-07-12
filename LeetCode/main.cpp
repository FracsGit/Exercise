#include "stdafx.h"

int main()
{
	int calculateMinimumHP(vector<vector<int>>& dungeon);

	vector<vector<int>> dungeon = { {-2,-3,3},{-5,-10,1},{10,30,-5} };
	
	cout << calculateMinimumHP(dungeon) << endl;

	system("Pause");
	return 0;
}