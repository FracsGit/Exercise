#include "S_139_WordBreak.h"

S_139_WordBreak::S_139_WordBreak()
{
}

S_139_WordBreak::~S_139_WordBreak()
{
}

void Update(const string& s, int position, unordered_set<string>& dictionary, vector<bool>& wordCheck)
{
	for (size_t l = position, r = position + 1; r <= s.size(); ++r)
	{
		if (wordCheck[r] && dictionary.find(s.substr(l, r - l)) != dictionary.end())
		{
			wordCheck[l] = true;
			return;
		}
	}
}

bool S_139_WordBreak::wordBreak(string s, vector<string>& wordDict)
{
	unordered_set<string> dictionary;
	for (string word : wordDict)
		dictionary.insert(word);
	vector<bool> wordCheck(s.size() + 1, false);
	wordCheck[s.size()] = true;

	for (int i = s.size() - 1; i >= 0; --i)
	{
		Update(s, i, dictionary, wordCheck);
	}

	return wordCheck[0];
}