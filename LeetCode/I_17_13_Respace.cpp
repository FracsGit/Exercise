#include "stdafx.h"

class Trie 
{
public:
	Trie* next[26] = { nullptr };
	bool isEnd;

	Trie() 
	{
		isEnd = false;
	}

	void insert(string s) 
	{
		Trie* node = this;

		for (int i = s.length() - 1; i >= 0; --i) 
		{
			int val = s[i] - 'a';
			if (node->next[val] == nullptr) 
			{
				node->next[val] = new Trie();
			}
			node = node->next[val];
		}
		node->isEnd = true;
	}
};

int respace(vector<string>& dictionary, string sentence)
{
	int n = sentence.length(), inf = 0x3f3f3f3f;

	Trie* root = new Trie();
	for (auto& s : dictionary) 
		root->insert(s);

	vector<int> cnt(n + 1, inf);
	cnt[0] = 0;
	for (int i = 1; i <= n; ++i) 
	{
		cnt[i] = cnt[i - 1] + 1;

		Trie* curPos = root;
		for (int j = i - 1; j >= 0; --j) 
		{
			int val = sentence[j] - 'a';
			if (curPos->next[val] == nullptr) 
				break;
			else if (curPos->next[val]->isEnd) 
				cnt[i] = min(cnt[i], cnt[j]);

			if (cnt[i] == 0) 
				break;
			curPos = curPos->next[val];
		}
	}
	return cnt[n];
}