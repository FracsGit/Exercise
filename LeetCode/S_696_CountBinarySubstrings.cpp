#include "stdafx.h"

int countBinarySubstrings(string s) 
{
	char current = '0';
	int cntPre = 0, cntCrt = 0;

	int result = 0;
	for (int i = 0; i != s.size(); ++i)
	{
		if (s[i] == current)
		{
			++cntCrt;
		}
		else
		{
			current = s[i];
			result += min(cntPre, cntCrt);
			cntPre = cntCrt;
			cntCrt = 1;
		}
	}
	result += min(cntPre, cntCrt);

	return result;
}