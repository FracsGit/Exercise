#include<string>
#include<iostream>
#include<stack>
#include <stdlib.h>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* recoverFromPreorder(string S)
{
	stack<TreeNode**> stk;
	stack<int> d;
	TreeNode* root;
	stk.push(&root);
	d.push(0);

	int size = S.size();
	int val = 0, depth = 0;
	bool readVal = true;
	for (int i = 0; i < size; ++i)
	{
		switch (S[i])
		{
		case '-':
			if (readVal)
			{
				while (d.top() != depth)
				{
					d.pop();
					stk.pop();
				}

				TreeNode** p = stk.top();
				stk.pop();
				d.pop();
				*p = new TreeNode(val);
				stk.push(&(*p)->right);
				stk.push(&(*p)->left);
				d.push(depth + 1);
				d.push(depth + 1);

				readVal = false;
				depth = 0;
				val = 0;
			}
			++depth;
			break;
		default:
			readVal = true;
			val *= 10;
			val += S[i] - '0';
			break;
		}
	}

	while (d.top() != depth)
	{
		d.pop();
		stk.pop();
	}
	*stk.top() = new TreeNode(val);

 	return root;
}

int main()
{
	string s1("1-2--3--4-5--6--7");
	recoverFromPreorder(s1);
	
	string s2("1-2--3---4-5--6---7");
	recoverFromPreorder(s2);
	
	string s3("1-401--349---90--88");
	recoverFromPreorder(s3);
	
	system("Pause");
	return 0;
}