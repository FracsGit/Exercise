#include "stdafx.h"

bool isSubsequence(string s, string t) 
{
	int ps = 0, pt = 0;

	while (ps != s.size() && pt != t.size())
	{
		while (s[ps] != t[pt])
		{
			++pt;
			if (pt == t.size())
				return false;
		}
		++ps;
		++pt;
	}

	return ps == s.size();
}