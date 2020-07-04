#include "stdafx.h"

int longestValidParentheses(string s) 
{
	stack<int> stk;
	int current = 0;
	int maxCount = 0;

	for (char c : s)
	{
		if (c == '(')
		{
			stk.push(0);
		}
		else if (!stk.empty())
		{
			if (stk.top() == 0)
			{
				stk.pop();
				current = 2;

				if (!stk.empty() && stk.top() != 0)
				{
					current += stk.top();
					stk.pop();
				}
				maxCount = max(maxCount, current);
				stk.push(current);
			}
			else
			{
				current = stk.top();
				stk.pop();
				if (!stk.empty())
				{
					current += 2;
					stk.pop();
				}
				else
				{
					continue;
				}
				if (!stk.empty() && stk.top() != 0)
				{
					current += stk.top();
					stk.pop();
				}
				maxCount = max(maxCount, current);
				stk.push(current);
			}
		}
	}

	return maxCount;
}