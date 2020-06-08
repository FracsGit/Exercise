#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<numeric>
using namespace std;

class UnionFind 
{
private:
	vector<int> parent;

public:
	UnionFind() 
	{
		parent.resize(26);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int index) 
	{
		if (index == parent[index]) 
			return index;
		parent[index] = find(parent[index]);
		return parent[index];
	}

	void unite(int index1, int index2) 
	{
		parent[find(index1)] = find(index2);
	}
};

bool equationsPossible(vector<string>& equations) 
{
	UnionFind uf;
	stack<pair<char, char>> unequal;

	for (const string& str : equations) 
	{
		if (str[1] == '=') 
		{
			int index1 = str[0] - 'a';
			int index2 = str[3] - 'a';
			uf.unite(index1, index2);
		}
		else
		{
			unequal.push({ str[0], str[3] });
		}

	}

	while (!unequal.empty())
	{
		if (uf.find(unequal.top().first - 'a') == uf.find(unequal.top().second - 'a'))
			return false;
		unequal.pop();
	}

	return true;
}

int main()
{
	vector<string> v1 = { "a==b","b!=a" };
	vector<string> v2 = { "b==a","a==b" };
	vector<string> v3 = { "a==b","b==c","a==c" };
	vector<string> v4 = { "a==b","b!=c","c==a" };
	vector<string> v5 = { "c==c","b==d","x!=z" };
	vector<string> v6 = { };
	vector<string> v7 = { "a!=a" };
	vector<string> v8 = { "b==a","a==b" };
	vector<string> v9 = { "c==c", "f!=a", "f==b", "b==c" };
	vector<string> v10 = { "a==b", "e==c", "b==c", "a!=e" };
	vector<string> v11 = { "b!=f", "c!=e", "f==f", "d==f", "b==f", "a==f" };

	cout << "v1: " << equationsPossible(v1) << endl;
	cout << "v2: " << equationsPossible(v2) << endl;
	cout << "v3: " << equationsPossible(v3) << endl;
	cout << "v4: " << equationsPossible(v4) << endl;
	cout << "v5: " << equationsPossible(v5) << endl;
	cout << "v6: " << equationsPossible(v6) << endl;
	cout << "v7: " << equationsPossible(v7) << endl;
	cout << "v8: " << equationsPossible(v8) << endl;
	cout << "v9: " << equationsPossible(v9) << endl;
	cout << "v10: " << equationsPossible(v10) << endl;
	cout << "v11: " << equationsPossible(v11) << endl;

	system("Pause");
	return 0;
}