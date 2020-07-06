#include "stdafx.h"

bool buddyStrings(string A, string B) 
{
	if (A.size() != B.size())
		return false;

	int count = 0;
	char a, b;

	for (size_t i = 0; i < A.size(); ++i)
	{
		if (A[i] != B[i])
		{
			++count;
			if (count > 2)
				return false;
			if (count == 1)
			{
				a = A[i];
				b = B[i];
			}
			if (count == 2)
			{
				if (A[i] != b || B[i] != a)
					return false;
			}
		}
	}
	if (count == 0)
	{
		int cnt[26] = { 0 };
		for (char c : A)
			++cnt[c - 'a'];
		for (int x : cnt)
			if (x > 1)
				return true;
		return false;
	}
	if (count == 1)
		return false;
	return true;
}