#include "stdafx.h"

vector<string> split(string s, int n)
{
	int length = s.size();
	if (length < n || length > n * 3)
		return vector<string>();

	if (n == 1)
	{
		if (stoi(s) > 255 || (length > 1 && s[0] == '0'))
			return vector<string>();
		return vector<string>() = { s };
	}

	vector<string> result;
	int l = max(0, length - n * 3 + 2);
	int r = min(2, length - n);
	for (int i = l; i <= r; ++i)
	{
		string temp = s.substr(0, i + 1);
		if (stoi(temp) > 255 || (static_cast<int>(temp.size()) > 1 && temp[0] == '0'))
			return result;

		temp += ".";
		vector<string> suffix = split(s.substr(i + 1), n - 1);
		for (string suf : suffix)
		{
			result.push_back(temp + suf);
		}
	}

	return result;
}

vector<string> restoreIpAddresses(string s) 
{
	return split(s, 4);
}