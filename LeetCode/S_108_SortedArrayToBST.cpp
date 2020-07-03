#include "stdafx.h"

void BuildBST(vector<int>& nums, int l, int r, TreeNode* &node)
{
	if (l == r)
	{
		node = new TreeNode(nums[l]);
		return;
	}
	if (l == r - 1)
	{
		node = new TreeNode(nums[r]);
		node->left = new TreeNode(nums[l]);
		return;
	}
	int m = (l + r + 1) / 2;
	node = new TreeNode(nums[m]);
	BuildBST(nums, l, m - 1, node->left);
	BuildBST(nums, m + 1, r, node->right);
}

TreeNode* sortedArrayToBST(vector<int>& nums) 
{
	if (nums.empty())
		return nullptr;
	TreeNode* root = nullptr;
	BuildBST(nums, 0, nums.size() - 1, root);
	return root;
}