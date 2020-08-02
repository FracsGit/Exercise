#include "stdafx.h"

int main()
{
	void flatten(TreeNode* root);

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	flatten(root);


	//cout << integerBreak(5) << endl;

	system("Pause");
	return 0;
}