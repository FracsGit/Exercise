#include "stdafx.h"

//0代表false， 1代表true， -1代表未算
int compare(string &s1, int p1, string &s2, int p2)
{
	int length1 = s1.size();
	int length2 = s2.size();
	if (length1 - p1 != length2 - p2)
		return 0;

	for (int i = 0; p1 + i != s1.size(); ++i)
	{
		if (s1[p1 + i] != s2[p2 + i])
			return 0;
	}

	return 1;
}

//0代表false， 1代表true， -1代表未算
int isInterleave(string &s1, int p1, string &s2, int p2, string &s3, int p3, vector<vector<int>> &result)
{
	if(result[p1][p2] != -1)
		return result[p1][p2];

	if (p1 == s1.size())
	{
		result[p1][p2] = compare(s2, p2, s3, p3);
		return result[p1][p2];
	}
	if (p2 == s2.size())
	{
		result[p1][p2] = compare(s1, p1, s3, p3);
		return result[p1][p2];
	}

	if (s1[p1] == s3[p3] && s2[p2] == s3[p3])
	{
		result[p1][p2] = isInterleave(s1, p1 + 1, s2, p2, s3, p3 + 1, result) || isInterleave(s1, p1, s2, p2 + 1, s3, p3 + 1, result);
		return result[p1][p2];
	}
	if (s1[p1] == s3[p3])
	{
		result[p1][p2] = isInterleave(s1, p1 + 1, s2, p2, s3, p3 + 1, result);
		return result[p1][p2];
	}
	if (s2[p2] == s3[p3])
	{
		result[p1][p2] = isInterleave(s1, p1, s2, p2 + 1, s3, p3 + 1, result);
		return result[p1][p2];
	}

	return 0;
}


bool isInterleave(string s1, string s2, string s3) 
{
	if (s1.size() + s2.size() != s3.size())
		return false;

	//0代表false， 1代表true， -1代表未算
	vector<vector<int>> result(s1.size() + 1, vector<int>(s2.size() + 1, -1));
	isInterleave(s1, 0, s2, 0, s3, 0, result);
	if (result[0][0] == 1)
		return true;
	return false;
}