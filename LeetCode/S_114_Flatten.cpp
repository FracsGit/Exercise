#include "stdafx.h"

void flatten(TreeNode* root) 
{
	TreeNode* current = root;
	while (current != nullptr)
	{
		while (current->left != nullptr)
		{
			TreeNode* pre = current->left;
			while (pre->right != nullptr)
				pre = pre->right;
			pre->right = current->right;
			current->right = current->left;
			current->left = nullptr;
		}
		current = current->right;
	}
}