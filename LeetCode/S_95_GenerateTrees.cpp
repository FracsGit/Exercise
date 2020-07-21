#include "stdafx.h"

vector<TreeNode*> generateTrees(vector<vector<vector<TreeNode*>>> &record, int l, int r)
{
	if (!record[l][r].empty())
		return record[l][r];
	if (l > r)
		return vector<TreeNode*>{nullptr};

	vector<TreeNode*> result;
	for (int i = l; i <= r; ++i)
	{
		vector<TreeNode*> left = generateTrees(record, l, i - 1);
		vector<TreeNode*> right = generateTrees(record, i + 1, r);
		for (TreeNode* leftNode : left)
		{
			for (TreeNode* rightNode : right)
			{
				result.push_back(new TreeNode(i, leftNode, rightNode));
			}
		}
	}

	return result;
}

vector<TreeNode*> generateTrees(int n) 
{
	vector<vector<vector<TreeNode*>>> record(n + 2, vector<vector<TreeNode*>>(n + 2, vector<TreeNode*>()));

	for (int i = n; i >= 1; --i)
	{
		for (int j = i; j <= n; ++j)
		{
			record[i][j] = generateTrees(record, i, j);
		}
	}

	return record[1][n];
}