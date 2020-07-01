#include "stdafx.h"

int findCommonLength(vector<int>& A, int la, vector<int>& B, int lb, int length)
{
	int maxLength = 0;
	int temp = 0;

	for (int i = 0; i < length; ++i)
	{
		if (A[la + i] == B[lb + i])
		{
			++temp;
		}
		else
		{
			maxLength = max(temp, maxLength);
			temp = 0;
		}
	}
	maxLength = max(temp, maxLength);

	return maxLength;
}

int findLength(vector<int>& A, vector<int>& B) 
{
	int maxLength = 0;
	int minSize = min(A.size(), B.size());
	int maxSize = max(A.size(), B.size());
	
	for (int i = 0; i < static_cast<int>(A.size() + B.size() - 1); ++i)
	{
		int la = A.size() - 1 - i;
		la = max(la, 0);
		int lb = 0;
		if (i >= static_cast<int>(A.size()))
			lb = i - A.size() + 1;

		if (i < minSize)
			maxLength = max(findCommonLength(A, la, B, lb, i + 1), maxLength);
		else if (i < maxSize)
			maxLength = max(findCommonLength(A, la, B, lb, minSize), maxLength);
		else
			maxLength = max(findCommonLength(A, la, B, lb, A.size() + B.size() - i - 1), maxLength);
	}

	return maxLength;
}