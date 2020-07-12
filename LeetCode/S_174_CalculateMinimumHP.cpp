#include "stdafx.h"

int calculateMinimumHP(vector<vector<int>>& dungeon) 
{
	if (dungeon.empty() || dungeon[0].empty())
		return 0;

	int x = dungeon.size();
	int y = dungeon[0].size();

	vector<vector<int>> hp(x + 1, vector<int>(y + 1, INT_MAX));
	hp[x][y - 1] = hp[x - 1][y] = 1;

	for (int i = x - 1; i >= 0; --i)
	{
		for (int j = y - 1; j >= 0; --j)
		{
			hp[i][j] = min(hp[i + 1][j], hp[i][j + 1]);
			hp[i][j] -= dungeon[i][j];
			hp[i][j] = max(1, hp[i][j]);
		}
	}

	return hp[0][0];
}