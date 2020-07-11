#include "stdafx.h"

struct CountTreeNode
{
	int val;
	int countSmall;
	int countEqual;
	CountTreeNode *left;
	CountTreeNode *right;
	CountTreeNode(int x) : val(x), countSmall(0), countEqual(1), left(nullptr), right(nullptr) {}
};

int countSmaller(int x, CountTreeNode* &node)
{
	if (node == nullptr)
	{
		node = new CountTreeNode(x);
		return 0;
	}

	if (x < node->val)
	{
		++node->countSmall;
		return countSmaller(x, node->left);
	}
	else if(x > node->val)
		return node->countSmall + node->countEqual + countSmaller(x, node->right);
	else
	{
		++node->countEqual;
		return node->countSmall;
	}
}

vector<int> countSmaller(vector<int>& nums) 
{
	vector<int> cnt(nums.size(), 0);

	CountTreeNode* root = nullptr;

	for (int i = nums.size() - 1; i >= 0; --i)
		cnt[i] = countSmaller(nums[i], root);

	return cnt;
}