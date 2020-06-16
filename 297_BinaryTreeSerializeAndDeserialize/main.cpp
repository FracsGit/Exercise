#include<string>
#include<stack>
#include<iostream>
using namespace std;

struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Encodes a tree to a single string.
class Codec 
{
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) 
	{
		stack<TreeNode*> stk;
		string s;
		stk.push(root);
		while (!stk.empty())
		{
			TreeNode* p = stk.top();
			stk.pop();
			if (p)
			{
				s += to_string(p->val) + ",";
				stk.push(p->right);
				stk.push(p->left);
			}
			else
			{
				s += "n";
			}
		}
		return s;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) 
	{
		stack<TreeNode**> stk;
		TreeNode* root = nullptr;
		TreeNode** p; 
		stk.push(&root);
		int size = data.size();
		int val = 0;
		bool positive = true;
		for (int i = 0; i < size; ++i)
		{
			switch (data[i])
			{
			case 'n':
				stk.pop();
				break;
			case ',':
				if (!positive)
				{
					positive = true;
					val = 0 - val;
				}
				p = stk.top();
				stk.pop();
				{
					*p = new TreeNode(val);
				}
				val = 0;
				stk.push(&(*p)->right);
				stk.push(&(*p)->left);
				break;
			case '-':
				positive = false;
				break;
			default:
				val *= 10;
				val += data[i] - '0';
				break;
			}
		}
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main()
{
	TreeNode* root = nullptr;
	TreeNode a[1] = { -1 };
	TreeNode b[2] = { 1, 2 };
	TreeNode c[4] = { 1, 2, 3, 4 };
	for (int i = 0; i < 1; ++i)
	{
		a[i].left = &b[2 * i];
		a[i].right = &b[2 * i + 1];
	}
	for (int i = 0; i < 2; ++i)
	{
		b[i].left = &c[2 * i];
		b[i].right = &c[2 * i + 1];
	}
	root = &a[0];

	Codec codec;
	codec.deserialize(codec.serialize(root));

	system("Pause");
	return 0;
}