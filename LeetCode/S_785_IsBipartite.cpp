#include "stdafx.h"

int checkOver(vector<int> &point)
{
	for (size_t i = 0; i < point.size(); ++i)
	{
		if (point[i] == 0)
			return i;
	}
	return -1;
}

bool check(vector<vector<int>>& graph, vector<int> &point, stack<int> &group1, stack<int> &group2)
{
	stack<int> *a = &group1;
	stack<int> *b = &group2;
	while (!a->empty())
	{
		int val1 = point[a->top()];
		int val2 = 1;
		if (val1 == 1)
			val2 = 2;

		while (!a->empty())
		{
			int p = a->top();
			a->pop();
			for (int x : graph[p])
			{
				if (point[x] == val1)
					return false;
				else if (point[x] == 0)
				{
					point[x] = val2;
					b->push(x);
				}
			}
		}

		stack<int> *temp = a;
		a = b;
		b = temp;
	}

	return true;
}

bool isBipartite(vector<vector<int>>& graph) 
{
	stack<int> group1, group2;
	vector<int> point(graph.size(), 0);

	int p = checkOver(point);
	while (p != -1)
	{
		point[p] = 1;
		group1.push(p);
		if (!check(graph, point, group1, group2))
			return false;

		p = checkOver(point);
	}
	return true;
}