#include<string>
#include<vector>
#include<iostream>
using namespace std;

string GetCommonString(string& s1, string& s2)
{
	int minSize = s1.size() < s2.size() ? s1.size() : s2.size();
	int count = 0;
	
	for (int i = 0; i < minSize; ++i)
	{
		if (s1[i]==s2[i])
		{
			++count;
		}
		else
		{
			break;
		}
	}
	string common(s1, 0, count);

	return common;
}


string longestCommonPrefix(vector<string>& strs) 
{
	if (strs.size() == 0)
		return "";
	if (strs.size() == 0)
		return strs[0];
	string common(strs[0]);
	for (int i = 1;i < static_cast<int>(strs.size()); ++i)
	{
		common = GetCommonString(common, strs[i]);
	}

	return common;
}

int main()
{
	vector<string> strs1 = {"",""};
	vector<string> strs2 = { "","a" };
	vector<string> strs3 = { "b","" };
	vector<string> strs4 = { "ab","ba" };
	vector<string> strs5 = { "abccccc","abddddd" };
	vector<string> strs6 = { "abcdddddd","abceeeeeee" };
	vector<string> strs7 = { "flower" };
	vector<string> strs8 = {  };

	cout << longestCommonPrefix(strs1) << endl;
	cout << longestCommonPrefix(strs2) << endl;
	cout << longestCommonPrefix(strs3) << endl;
	cout << longestCommonPrefix(strs4) << endl;
	cout << longestCommonPrefix(strs5) << endl;
	cout << longestCommonPrefix(strs6) << endl;
	cout << longestCommonPrefix(strs7) << endl;
	cout << longestCommonPrefix(strs8) << endl;

	system("Pause");
	return 0;
}