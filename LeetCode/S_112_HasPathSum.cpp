#include "stdafx.h"

bool hasPathSum(TreeNode* root, int sum) 
{
	stack<TreeNode *> node;
	stack<int> nodeSum;

	if (root == nullptr)
		return false;
	node.push(root);
	nodeSum.push(root->val);
	while (!node.empty())
	{
		if (node.top()->left == nullptr && node.top()->right == nullptr)
		{
			if (nodeSum.top() == sum)
				return true;
			node.pop();
			nodeSum.pop();
			continue;
		}
		TreeNode* temp = node.top();
		node.pop();
		int tempSum = nodeSum.top();
		nodeSum.pop();

		if (temp->right != nullptr)
		{
			node.push(temp->right);
			nodeSum.push(tempSum + node.top()->val);
		}

		if (temp->left != nullptr)
		{
			node.push(temp->left);
			nodeSum.push(tempSum + node.top()->val);
		}
	}
	return false;
}