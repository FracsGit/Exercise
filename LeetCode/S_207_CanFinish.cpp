#include "stdafx.h"

bool update(vector<vector<int>> &record, int base, int pre)
{
	if (base == pre)
		return false;

	for (int x : record[base])
	{
		if (pre == x)
			return true;
	}

	for (int x : record[pre])
	{
		if (!update(record, base, x))
			return false;
	}

	record[base].push_back(pre);
	return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
	vector<vector<int>> record(numCourses);

	for (vector<int> pre : prerequisites)
	{
		if (!update(record, pre[0], pre[1]))
			return false;
	}
	return true;
}