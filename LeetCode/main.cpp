#include "stdafx.h"

int main()
{
	bool isBipartite(vector<vector<int>>& graph);
	vector<vector<int>> graph = { {1, 3},{0, 2},{1, 3},{0, 2} };

	cout << isBipartite(graph) << endl;

	system("Pause");
	return 0;
}