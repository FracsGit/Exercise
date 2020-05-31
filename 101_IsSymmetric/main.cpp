#include<iostream>
using namespace std;

struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool check(TreeNode *p, TreeNode *q)
{
	if (!p && !q) return true;
	if (!p || !q) return false;
	return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}

bool isSymmetric(TreeNode* root)
{
	return check(root, root);
}

int main()
{



	system("Pause");
	return 0;
}