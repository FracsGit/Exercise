#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

bool CompareWord(const string& str1, const string& str2)
{
	int differences = 0;
	for (size_t i = 0; i < str1.size() && differences < 2; i++)
	{
		if (str1[i] != str2[i])
			++differences;
	}
	return differences == 1;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_map<string, int> wordId;
	vector<vector<int>> edges;

	int id = 0;
	for (const string& word : wordList)
		wordId.insert({ word, id++ });

	if (!wordId.count(endWord))
		return {};

	bool flagAddBeginWord = false;
	if (!wordId.count(beginWord))
	{
		flagAddBeginWord = true;
		wordId[beginWord] = id++;
		wordList.push_back(beginWord);
	}

	//½¨Í¼
	edges.resize(wordList.size());
	for (size_t i = 0; i < wordList.size(); i++)
	{
		for (size_t j = i + 1; j < wordList.size(); j++)
		{
			if (CompareWord(wordList[i], wordList[j]))
			{
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
		}
	}

	vector<vector<string>> result;
	const int dest = wordId[endWord];
	queue<vector<int>> q;
	vector<int> cost(id, INT32_MAX);

	q.push(vector<int>{wordId[beginWord]});
	cost[wordId[beginWord]] = 0;

	bool notOver = true;
	while (!q.empty())
	{
		int last = q.front().back();
		if (last == dest)
		{
			notOver = false;
			vector<string> temp;
			for (int index : q.front())
				temp.push_back(wordList[index]);

			result.push_back(temp);
		}
		else
		{
			if (notOver)
			{
				for (size_t i = 0; i < edges[last].size(); i++)
				{
					int nextNode = edges[last][i];
					if (cost[last] + 1 <= cost[nextNode])
					{
						cost[nextNode] = cost[last] + 1;
						vector<int> temp(q.front());
						temp.push_back(nextNode);
						q.push(temp);
					}
				}
			}
		}

		q.pop();
	}

	if (flagAddBeginWord)
		wordList.pop_back();

	return result;
}

	

int main()
{
	string b1 = "hit";
	string e1 = "cog";
	vector<string> l1 = { "hot", "dot", "dog", "lot", "log", "cog" };
	vector<vector<string>> a1 = findLadders(b1, e1, l1);

	for (vector<string> v : a1)
	{
		for (string s : v)
			cout << s << " ";
		cout << endl;
	}

	string b2 = "cat";
	string e2 = "fin";
	vector<string> l2 = { "ion","rev","che","ind","lie","wis","oct","ham","jag","ray","nun","ref","wig","jul",
		"ken","mit","eel","paw","per","ola","pat","old","maj","ell","irk","ivy","beg","fan","rap","sun","yak",
		"sat","fit","tom","fin","bug","can","hes","col","pep","tug","ump","arc","fee","lee","ohs","eli","nay",
		"raw","lot","mat","egg","cat","pol","fat","joe","pis","dot","jaw","hat","roe","ada","mac" };
	vector<vector<string>> a2 = findLadders(b2, e2, l2);

	for (vector<string> v : a2)
	{
		for (string s : v)
			cout << s << " ";
		cout << endl;
	}


	system("Pause");
	return 0;
}