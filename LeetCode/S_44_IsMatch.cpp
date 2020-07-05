#include "stdafx.h"

bool checkBoth(string &s, string &p)
{
	if (s.size() != p.size())
		return false;

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (p[i] != '?' && s[i] != p[i])
			return false;
	}

	return true;
}

bool checkRight(string &s, int ls, int rs, string &p, int lp, int rp)
{
	if (rs - ls < rp - lp)
		return false;
	
	for (int i = 1; i <= rp - lp; ++i)
	{
		if (p[rp - i] != '?' && s[rs - i] != p[rp - i])
			return false;
	}

	return true;
}

bool compare(string &s, int ls, int rs, string &p, int lp, int rp)
{
	if (rs - ls < rp - lp)
		return false;

	for (int i = 0; lp + i < rp; ++i)
	{
		if (p[lp + i] != '?' && s[ls + i] != p[lp + i])
			return false;
	}

	return true;
}

int find(string &s, int ls, int rs, string &p, int lp, int rp)
{
	int r = rs - rp + lp;
	for (int i = 0; ls + i <= r; ++i)
	{
		if (compare(s, ls + i, rs, p, lp, rp))
			return ls + i + rp - lp;
	}

	return -1;
}

bool isMatch(string s, string p) 
{
	int ls = 0, rs = s.size();
	int lp = 0, rp = 0;
	bool hasStar = false;

	for (;rp != p.size(); ++rp)
	{
		while (rp != p.size() && p[rp] != '*')
			++rp;
		if (rp == p.size())
			break;

		if (!hasStar)
		{
			if (compare(s, ls, rs, p, lp, rp))
				ls = rp;
			else
				return false;
		}
		else
		{
			ls = find(s, ls, rs, p, lp, rp);
			if (ls == -1)
				return false;
		}
		
		lp = rp + 1;
		hasStar = true;
	}

	if (rp > 0 && p[rp - 1] == '*')
	{
		return true;
	}

	if (!hasStar)
	{
		return checkBoth(s, p);
	}
	else
	{
		if (checkRight(s, ls, rs, p, lp, p.size()))
			return true;
	}

	return false;
}